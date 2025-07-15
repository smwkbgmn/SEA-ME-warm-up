#include "SportsCar.hpp"

#include <iostream>

SportsCar::SportsCar(): _topSpeed(200) {
	std::cout << "SportsCar default constructor called" << std::endl;
}

SportsCar::SportsCar(const Car& car, size_t topSpeed): Car(car), _topSpeed(topSpeed) {
	std::cout << "SportsCar parameterized constructor called" << std::endl;
}

SportsCar::SportsCar(const SportsCar& other): Car(other) {
	*this = other;
	std::cout << "SportsCar copy constructor called" << std::endl;
}

SportsCar::~SportsCar() {
	std::cout << "SportsCar destructor called" << std::endl;
}

SportsCar& SportsCar::operator=(const SportsCar& other) {
	if (this != &other) {
		Car::operator=(other);
		_topSpeed = other._topSpeed;
		std::cout << "SportsCar assignment operator called" << std::endl;
	}
	return *this;
}

void SportsCar::drive() const {
	Car::drive();
	std::cout << "Top speed: " << _topSpeed << " km/h" << std::endl;
}