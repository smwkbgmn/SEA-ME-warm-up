#include "Car.hpp"

#include <iostream>

int main() {
	Car car1; // Default constructor
	car1.setNmae("Toyota");
	car1.setSpeed(120);

	std::cout << car1.getName() << " is moving at " << car1.getSpeed() << " km/h." << std::endl;

	Car car2(car1); // Copy constructor
	std::cout << car2.getName() << " is moving at " << car2.getSpeed() << " km/h." << std::endl;

	Car car3; // Another instance
	car3.setNmae("Honda");
	car3.setSpeed(100);

	std::cout << car3.getName() << " is moving at " << car3.getSpeed() << " km/h." << std::endl;

	car3 = car1; // Assignment operator
	std::cout << car3.getName() << " is moving at " << car3.getSpeed() << " km/h." << std::endl;

	return 0;
}