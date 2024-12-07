#include "Fixed.hpp"

Fixed::Fixed() : _value(0) 
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = intValue << bits;
}

Fixed::Fixed(const float floatVal)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatVal * (1 << bits));
}
Fixed::Fixed(const Fixed& another)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = another;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& another)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (*this == another) {return *this;}
	_value = another.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(_value) / (1 << bits);
}

int Fixed::toInt( void ) const
{
	return _value >> bits;
}

bool Fixed::operator>(const Fixed& another) const
{
	return (_value > another._value);
}

bool Fixed::operator<(const Fixed& another) const
{
	return (_value < another._value);
}

bool Fixed::operator>=(const Fixed& another) const
{
	return (_value >= another._value);
}

bool Fixed::operator<=(const Fixed& another) const
{
	return (_value <= another._value);
}

bool Fixed::operator==(const Fixed& another) const
{
	return (_value == another._value);
}

bool Fixed::operator!=(const Fixed& another) const
{
	return (_value != another._value);
}

Fixed Fixed::operator+(const Fixed&  another) const 
{
	Fixed result;
	result.setRawBits(_value + another._value);
	return result;
}

Fixed Fixed::operator-(const Fixed&  another) const 
{
	Fixed result;
	result.setRawBits(_value - another._value);
	return result;
}

Fixed Fixed::operator*(const Fixed&  another) const 
{
	return Fixed(this->toFloat() *another.toFloat());
}


Fixed Fixed::operator/(const Fixed& another) const
{
	if (another._value == 0)
	{
		std::cerr << "Error: Division by zero!" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() /another.toFloat());
}

Fixed& Fixed::operator++()
{
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value += 1;
	return temp;
}

Fixed& Fixed::operator--()
{
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& obj)
{
	ostream << obj.toFloat();
	return ostream;
}







