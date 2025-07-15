#include "SportsCar.hpp"

#include <iostream>

const std::string SportsCar::_description = "A high-performance car designed for speed and agility.";

SportsCar::SportsCar(const Model& model, const std::string& serial)
	: Car(model), _name(model.name), _serial(serial) {
	std::cout << "SportsCar parameterized constructor called" << std::endl;
}

SportsCar::SportsCar(const SportsCar& other)
	: Car(other), _name(other._name), _serial(other._serial) {
	std::cout << "SportsCar copy constructor called" << std::endl;
}

SportsCar::~SportsCar() {
	std::cout << "SportsCar destructor called" << std::endl;
}

SportsCar& SportsCar::operator=(const SportsCar& other) {
	if (this != &other) {
		Car::operator=(other);
		_name = other._name;
		_serial = other._serial;
		std::cout << "SportsCar assignment operator called" << std::endl;
	}
	return *this;
}

const std::string& SportsCar::getDescription() const {
	return _description;
}

SportsCar::Model SportsCar::getInfo() const {	
	return {{Car::getInfo()}, _name};
}

const std::string& SportsCar::getSerial() const {
	return _serial;
}

void SportsCar::drive() const {
	std::cout << "Driving a [" + _name + " " + _serial + "].\n";
}

void SportsCar::stop() const {
	std::cout << "Stopping the [" + _name + " " + _serial + "].\n";
}