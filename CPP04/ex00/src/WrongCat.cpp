#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat created\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copied\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other) {return *this;}
	this->type = other.type;
	std::cout << "WrongCat assigned\n";
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Meow! Meow!\n";
}