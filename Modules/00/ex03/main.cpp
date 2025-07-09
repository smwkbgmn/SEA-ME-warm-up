#include "PhoneBook.hpp"

#include <iostream>

using namespace std;

int main() {
	PhoneBook book;
	cout << "Welcome to the PhoneBook application!\n";

	string op = "init";
	while (op != "exit") {
		cout << "Choose an action (add, search, remove, bookmark, exit): ";
		cin >> op;

		if (PhoneBook::actions.find(op) == PhoneBook::actions.end()) {
			cout << "Invalid action. Please try again.\n";
			continue;
		}
		
		switch (PhoneBook::actions.at(op)) {
			case PhoneBook::ADD: {
				string name, number, nickname;

				cout << "Enter name: ";
				cin >> name;
				cout << "Enter phone number: ";
				cin >> number;
				cout << "Enter nickname: ";
				cin >> nickname;

				book.add(name, number, nickname);
				break;
			}
			case PhoneBook::SEARCH: {
				book.search();
				break;
			}
			case PhoneBook::REMOVE: {
				cout << "Enter index or phone number to remove: ";
				string target;
				cin >> target;

				if (target.length() < 3) {
					book.remove(static_cast<size_t>(stoi(target)));
				} else {
					book.remove(target);
				}
				break;
			}
			case PhoneBook::BOOKMARK: {
				book.bookmark();
				break;
			}
			case PhoneBook::EXIT: {
				cout << "Exiting the program.\n";
				break;
			}
		}
	}
	return 0;
}