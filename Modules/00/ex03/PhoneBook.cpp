#include "PhoneBook.hpp"

# include <iostream>
# include <algorithm>
# include <iterator>

using namespace std;

// Action names to enum mapping for readability
const map<string, PhoneBook::ContactActions> PhoneBook::actions = {
    {"add", PhoneBook::ADD},
    {"search", PhoneBook::SEARCH},
    {"remove", PhoneBook::REMOVE},
    {"bookmark", PhoneBook::BOOKMARK},
	{"exit", PhoneBook::EXIT}
};

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
	if (_contacts.size() >= MAX_CONTACTS) {
		cout << "PhoneBook is full. Remove any contact first.\n";
		_clearScreen(1);
		return;
	}

	string name, number, nickname;

	cout << "Enter name: ";
	cin >> name;
	cout << "Enter phone number: ";
	cin >> number;
	cout << "Enter nickname: ";
	cin >> nickname;

	_contacts.push_back({name, number, nickname});
	
	cout << "Contact added!\n" << name + "\n" + number + "\n" + nickname + "\n";
	_clearScreen(1);
}

void PhoneBook::search() {
	// Exit if no contacts are available
	if (_contacts.empty()) {
		cout << "No contacts available.\n";
		_clearScreen(1);
		return;
	}

	_printContact(1);
	
	cout << "Enter the index of the contact you want to view: ";
	size_t i;
	cin >> i;

	// Exit if the index is invalid
	if (i >= _contacts.size()) {
		cout << "Invalid index.\n";
		_clearScreen(1);
		return;
	}

	_searchViewDetail(i);
	if (_searchAddBookmark(i)) {
		_holdScreen();
	}
	_clearScreen(0);
}

void PhoneBook::_searchViewDetail(size_t i) const {
	for (auto& s: _contacts[i]) {
		cout << s << "\n";
	}
}

bool PhoneBook::_searchAddBookmark(size_t i) {
	cout << "Do you want to bookmark this contact? (y/n): ";
	char c;
	cin >> c;

	if (c == 'y' || c == 'Y') {
		if (find(_bookmarks.begin(), _bookmarks.end(), _contacts[i][NAME]) != _bookmarks.end()) {
			cout << "Contact already bookmarked.\n";
		} else {
			_bookmarks.push_back(_contacts[i][NAME]);
			cout << "Contact bookmarked.\n";
		}
		return true;
	}
	return false;
}

void PhoneBook::remove() {
	if (_contacts.empty()) {
		cout << "No contacts available to remove.\n";
		_clearScreen(1);
		return;
	}

	cout << "Enter index or phone number to remove: ";
	string target;
	cin >> target;

	if (target.length() < 3) {
		_removeByIndex(stoi(target));
	} else {
		_removeByNumber(target);
	}
	_clearScreen(1);
}

void PhoneBook::_removeByIndex(size_t i) {
	if (i >= _contacts.size()) {
		cout << "Invalid index.\n";
		return;
	}

	_bookmarks.remove(_contacts[i][NAME]);
	_contacts.erase(_contacts.begin() + i);

	cout << "Contact removed.\n";
}

void PhoneBook::_removeByNumber(const string& number) {
	auto it = find_if(_contacts.begin(), _contacts.end(), [&number](const vector<string>& contact) {
		return contact[NUMBER] == number;
	});

	if (it != _contacts.end()) {
		_bookmarks.remove((*it)[NAME]);
		_contacts.erase(it);

		cout << "Contact with number " << number << " removed.\n";
	} else {
		cout << "No contact found with number " << number << ".\n";
	}
}

void PhoneBook::bookmark() const {
	if (_bookmarks.empty()) {
		cout << "No bookmarks available.\n";
		_clearScreen(1);
		return;
	}

	cout << "Bookmarks:\n";
	_printContact(_bookmarks);
	_clearScreen(1);
}

void PhoneBook::_printContact(int field) const {
	for (int i = 0; i < static_cast<int>(_contacts.size()); ++i) {
		cout << i << " | ";

		for (int j = 0; j < field; ++j) {
			cout << _contacts[i][j];

			if (j + 1 < field) {
				cout << ", ";
			} else {
				cout << "\n";
			}
		}
	}
}

void PhoneBook::_printContact(size_t index) const {
	cout << _contacts[index][NAME] + ", "
	     << _contacts[index][NUMBER] + ", "
	     << _contacts[index][NICKNAME] << "\n";
}

void PhoneBook::_printContact(const list<string>& bookmark) const {
	for (const auto& name: bookmark) {
		auto it = find_if(_contacts.begin(), _contacts.end(), [&name](const vector<string>& contact) {
			return contact[NAME] == name;
		});

		if (it != _contacts.end()) {
			_printContact(static_cast<size_t>(distance(_contacts.begin(), it)));
		}
	}
}

void PhoneBook::_holdScreen() const {
	// Clear any leftover characters in the input buffer (e.g., a previous '\n' from std::cin >>)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Wait for a newline character (i.e., the Enter key)
    std::cin.get();
}

void PhoneBook::_clearScreen(int op) const {
	if (op == 1) _holdScreen();

	cout << CLEAR_SCREEN;
	cout.flush();
}
