#include "SportsCar.hpp"

#include <iostream>

int main() {
	/* The Car class is ABSTRACT, which is saying that it's a role of concept for more complex instance that will be derived from it.
	So we cannot instantiate it directly. It may not be the concrete one */
	// Car brandVolkswagen({"VolksWagen", 2024});

	/* The SportsCar class made up with (INHERIT / DERIVED FROM) Car class, as it's obviously one of a car.
	If we want to create a new model, that also will be one of the car, we can reuse the Car class. 
	Like a LEGO brick, we can create many shapes (POLYMORPHISM) from one concetp. */
	SportsCar::Model golf = {{"VolksWagen", 2024}, "Golf GTI"};
	SportsCar newCar(golf, "2025-42424");
	std::cout << '\n';
	
	/* We may NOT directly access member variables of the Car class (ENCAPSULATE and ISOLATE) so that it conceal the implementation details and what members are there. */
	SportsCar::Model newCarInfo = newCar.getInfo();
	std::cout << "The category SportsCar: " + newCar.getDescription() << '\n';
	std::cout << "This model is a " << newCarInfo.make << " " << newCarInfo.name << " " << newCarInfo.year << " signed with " << newCar.getSerial() << "";

	/* The SportsCar class have some features. And we just use this at or when where we want to without knowing how it is working.
	Like a MODULE, bring it to code, and execute. That's all we need to know. */
	newCar.drive();
	newCar.stop();
	std::cout << '\n';

	return 0;
}