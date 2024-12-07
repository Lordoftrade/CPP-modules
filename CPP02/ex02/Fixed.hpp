#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
	private:
		int _value;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatVal);
		Fixed(const Fixed& another);
		~Fixed();

		Fixed& operator=(const Fixed& another);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>(const Fixed& another) const;
		bool operator<(const Fixed& another) const;
		bool operator>=(const Fixed& another) const;
		bool operator<=(const Fixed& another) const;
		bool operator==(const Fixed& another) const;
		bool operator!=(const Fixed& another) const;

		Fixed operator+(const Fixed& another) const;
		Fixed operator-(const Fixed& another) const;
		Fixed operator*(const Fixed& another) const;
		Fixed operator/(const Fixed& another) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& ostream, const Fixed& obj);

#endif