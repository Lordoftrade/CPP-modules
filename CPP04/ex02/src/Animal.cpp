#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal created\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copied\n";
}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other) {return *this;}
	
	type = other.type;
	std::cout << "Animal assigned\n";
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed\n";
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound\n";
}
