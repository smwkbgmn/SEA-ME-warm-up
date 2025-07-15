#include "Car.hpp"

#include <iostream>

Car::Car(const Manufacturer& mnf) : _make(mnf.make), _year(mnf.year) {
	std::cout << "Car parameterized constructor called" << std::endl;
}

Car::Car(const Car& other) : _make(other._make), _year(other._year) {
	std::cout << "Car copy constructor called" << std::endl;
}

Car::~Car() {
	std::cout << "Car destructor called" << std::endl;
}

Car& Car::operator=(const Car& other) {
	if (this != &other) {
		_make = other._make;
		_year = other._year;
		std::cout << "Car assignment operator called" << std::endl;
	}
	return *this;
}

Car::Manufacturer Car::getInfo() const {
	return {_make, _year};
}
