#include "Car.hpp"

#include <iostream>

Car::Car(): _name(""), _speed(0) {
	std::cout << "Car default constructor called" << std::endl;
}

Car::Car(const Car& other): _name(other._name), _speed(other._speed) {
	*this = other;
	std::cout << "Car copy constructor called" << std::endl;
}

Car::~Car() {
	std::cout << "Car destructor called" << std::endl;
}

Car& Car::operator=(const Car& other) {
	if (this != &other) {
		_name = other._name;
		_speed = other._speed;
		std::cout << "Car assignment operator called" << std::endl;
	}
	return *this;
}

const std::string& Car::getName() const {
	return _name;
}

const int& Car::getSpeed() const {
	return _speed;
}

void Car::setNmae(const std::string& name) {
	_name = name;
}

void Car::setSpeed(const int speed) {
	_speed = speed;
}