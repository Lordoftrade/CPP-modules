//#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cerrno>
#include <cstdlib>
//#include <climits>
#include <limits>
#include <cmath>

#include <iomanip>

enum ScalarType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter {
public:
	static void convert(const std::string& input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();
};

#endif
