#ifndef CAR_HPP
# define CAR_HPP

# include <string>

class Car {
	public:
		struct Manufacturer {
			std::string make;
			size_t year;
		};

		Car() = delete;
		Car(const Manufacturer&);
		Car(const Car&);
		virtual ~Car();

		Car& operator=(const Car&);

		virtual const std::string& getDescription() const = 0;
		Manufacturer getInfo() const;

		virtual void drive() const = 0;
		virtual void stop() const = 0;

	private:
		std::string _make;
		size_t _year;
};


#endif