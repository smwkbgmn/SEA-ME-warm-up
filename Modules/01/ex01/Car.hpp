#ifndef CAR_HPP
# define CAR_HPP

# include <string>

class Car {
	public:
		Car();
		Car(const std::string&, const std::string&, size_t);
		Car(const Car&);
		virtual ~Car();

		Car& operator=(const Car&);

		void drive() const;

	private:
		std::string _make;
		std::string _model;
		size_t _year;
};


#endif