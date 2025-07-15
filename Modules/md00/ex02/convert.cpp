#include <string>
#include <iostream>

using namespace std;

int main(int ac, char** av) {
	if (ac == 3) {
		string op(av[1]), s(av[2]);

		if (op == "up") {
			for (auto& c: s) {
				c = toupper(c);
			}
		} else if (op == "down") {
			for (auto& c: s) {
				c = tolower(c);
			}
		} else {
			cerr << "Invalid operation: " << op << "\n";
			return 1;
		}

		cout << s << "\n";
	} else {
		cerr << "Usage: \"up\" / \"down\" <string>\n";
	}
	return 0;
}