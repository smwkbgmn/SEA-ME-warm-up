#include "SportsCar.hpp"

#include <iostream>

int main() {
	Car car1("Toyota", "Corolla", 2022);
	Car car2("Ferrari", "488", 2020);

	SportsCar sc1(car1, 250);
	SportsCar sc2(car2, 340);

	std::cout << std::endl;

	sc1.drive();
	sc2.drive();

	sc2 = sc1; // Test assignment operator
	sc2.drive(); // Should show the same details as sc1
	
	return 0;
}