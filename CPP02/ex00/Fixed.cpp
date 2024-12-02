#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" std::cout::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" std::cout::endl;
}
Fixed::Fixed(const Fixed& another) : value(another.value)
{
	std::cout << "Copy constructor called" std::cout::endl;
}

Fixed& Fixed::operator=(const Fixed& another)
{
	if (this == &another) {return *this}

	value = another.value;
	return *this
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}