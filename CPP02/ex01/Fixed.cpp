/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:19:11 by mgreshne          #+#    #+#             */
/*   Updated: 2024/12/02 22:19:19 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& another)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = another;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_value = intValue << bits; 
}

Fixed::Fixed(const float floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatVal * (1 << bits));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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

Fixed& Fixed::operator=(const Fixed& another)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &another) {return *this;}
	_value = another.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& obj)
{
	ostream << obj.toFloat();
	return ostream;
}
