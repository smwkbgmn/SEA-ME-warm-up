#ifndef SPORTSCAR_HPP
# define SPORTSCAR_HPP

# include "Car.hpp"

class SportsCar : public Car {
	public:
		SportsCar();
		SportsCar(const Car&, size_t);
		SportsCar(const SportsCar&);
		~SportsCar();

		SportsCar& operator=(const SportsCar&);

		void drive() const;

	private:
		size_t _topSpeed;
};

#endif