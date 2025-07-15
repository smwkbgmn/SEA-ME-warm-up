#include "Car.hpp"

#include <iostream>

Car::Car(): _year(2025) {
	std::cout << "Car default constructor called" << std::endl;
}

Car::Car(const std::string& make, const std::string& model, size_t year)
	: _make(make), _model(model), _year(year) {
	std::cout << "Car parameterized constructor called" << std::endl;
}

Car::Car(const Car& other) {
	*this = other;
	std::cout << "Car copy constructor called" << std::endl;
}

Car::~Car() {
	std::cout << "Car destructor called" << std::endl;
}

Car& Car::operator=(const Car& other) {
	if (this != &other) {
		_make = other._make;
		_model = other._model;
		_year = other._year;
		std::cout << "Car assignment operator called" << std::endl;
	}
	return *this;
}

void Car::drive() const {
	std::cout << "Driving a " << _make << " " << _model << " " << _year << std::endl;
}