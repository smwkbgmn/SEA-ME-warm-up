#ifndef CAR_HPP
# define CAR_HPP

# include <string>

class Car {
public:
	Car();
	Car(const Car&);
	~Car();

	Car& operator=(const Car&);

	const std::string& getName() const;
	const int& getSpeed() const;
	void setNmae(const std::string&);
	void setSpeed(const int speed);

private:
	std::string _name;
	int _speed;
};


#endif