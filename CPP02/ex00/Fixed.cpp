#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& another)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = another;
}

Fixed& Fixed::operator=(const Fixed& another)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &another) {return *this;}
	value = another.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
