#include "Dog.hpp"

Dog::Dog() 
	: Animal()
{
	this->type = "Dog";
	std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	*this = other;
	std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other) {return *this;}
	
	type = other.type;
	std::cout << "Dog copy assignment operator" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed\n";
}
void Dog::makeSound() const
{
	std::cout << "Woof! Woof!\n";
}


