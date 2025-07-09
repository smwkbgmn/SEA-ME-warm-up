#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <vector>
# include <list>
# include <map>

# define MAX_CONTACTS 8
# define CLEAR_SCREEN "\033[2J\033[1;1H"

class PhoneBook {
	public:
		enum ContactFields {
			NAME,
			NUMBER,
			NICKNAME
		};

		enum ContactActions {
			ADD,
			SEARCH,
			REMOVE,
			BOOKMARK,
			EXIT
		};

		static const std::map<std::string, ContactActions> actions;

		PhoneBook();
		~PhoneBook();
		
		void add(const std::string &, const std::string &, const std::string &);
		void remove(size_t);
		void remove(const std::string&);
		void search();
		void bookmark() const;
		
	private:
		std::vector<std::vector<std::string>> _contacts;
		std::list<std::string> _bookmarks;

		void _printContact(int) const;
		void _printContact(size_t) const;
		void _printContact(const std::list<std::string>&) const;
		void _searchViewDetail(size_t) const;
		bool _searchAddBookmark(size_t);
		void _holdScreen() const;
		void _clearScreen(int) const;
};

#endif 