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
			case PhoneBook::ADD			: book.add(); break;
			case PhoneBook::SEARCH		: book.search(); break;
			case PhoneBook::REMOVE		: book.remove(); break;
			case PhoneBook::BOOKMARK	: book.bookmark(); break;
			case PhoneBook::EXIT		: {
				cout << "Exiting the program.\n";
				break;
			}
		}
	}

	return 0;
}