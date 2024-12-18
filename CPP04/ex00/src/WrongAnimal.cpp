#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal created\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal copied\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other) {return *this;}

	type = other.type;
	std::cout << "WrongAnimal assigned\n";
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a sound\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}

