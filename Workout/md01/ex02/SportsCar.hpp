#ifndef SPORTSCAR_HPP
# define SPORTSCAR_HPP

# include "Car.hpp"

class SportsCar : public Car {
	public:
		// Model specification for SportsCar
		struct Model : public Manufacturer {
			std::string name;
		};

		SportsCar() = delete;
		SportsCar(const Model&, const std::string&);
		SportsCar(const SportsCar&);
		~SportsCar();

		SportsCar& operator=(const SportsCar&);

		const std::string& getDescription() const override;

		Model getInfo() const;
		const std::string& getSerial() const;

		void drive() const override;
		void stop() const override;

	private:
		// Global constant description for SportsCar
		static const std::string _description;

		std::string _name;
		std::string _serial;
};

#endif