#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>


class Fixed {
	private:
		int _value;
		static const int bits = 8;


	public:
		Fixed();
	//Преобразует целое число в представление с фиксированной запятой.
		Fixed(const int intValue);
	//Преобразует число с плавающей запятой в представление с фиксированной запятой.
		Fixed(const float floatVal);
		Fixed(const Fixed& another);
		~Fixed();

		Fixed& operator=(const Fixed& another);

		//которая преобразует значение с фиксированной запятой в значение с плавающей запятой.
		float toFloat( void ) const;

		// которая преобразует значение с фиксированной запятой в целое значение.
		int toInt( void ) const;
};




#endif
