#include "ScalarConverter.hpp"

static bool isChar(const std::string& input) {
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	return false;
}

static bool isInt(const std::string& input) {
	char* end;
	errno = 0;
	long value = ::strtol(input.c_str(), &end, 10);
	return (*end == '\0' && errno != ERANGE && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max());
}

static bool isFloat(const std::string& input) {
	char* end;
	errno = 0;
	std::strtod(input.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0' && errno == 0);
}

static bool isDouble(const std::string& input) {
	char* end;
	errno = 0;
	std::strtod(input.c_str(), &end);
	return (*end == '\0' && errno == 0);
}

static ScalarType determineType(const std::string& input) {
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return FLOAT;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return DOUBLE;

	if (isChar(input)) return CHAR;
	if (isInt(input)) return INT;
	if (isFloat(input)) return FLOAT;
	if (isDouble(input)) return DOUBLE;
	return UNKNOWN;
}

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor is not working" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter the destructor is not working" << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
	ScalarType type = determineType(input);

	if (type == FLOAT) {
		double value = std::strtod(input.c_str(), NULL);
		if (input == "nanf" || input == "+inff" || input == "-inff") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		} else {
			if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
				char c = static_cast<char>(value);
				if (std::isprint(c)) {
					std::cout << "char: '" << c << "'" << std::endl;
				} else {
					std::cout << "char: Non displayable" << std::endl;
				}
			} else {
				std::cout << "char: impossible" << std::endl;
			}

			if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
				std::cout << "int: " << static_cast<int>(value) << std::endl;
			} else {
				std::cout << "int: impossible" << std::endl;
			}

			if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
				std::cout << "float: impossible" << std::endl;
			} else {

				if (value == static_cast<int>(value)) {
					std::cout << "float: " << value << ".0f" << std::endl;
					std::cout << "double: " << static_cast<double>(value) << ".0" <<std::endl;
				} else {
					std::cout << "float: " << value << "f" << std::endl;
					std::cout << "double: " << static_cast<double>(value) << std::endl;
				}
			}
		}
	} else if (type == DOUBLE) {
		double value = std::strtod(input.c_str(), NULL);
		if (input == "nan" || input == "+inf" || input == "-inf") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << input + "f" << std::endl;
			std::cout << "double: " << input << std::endl;
		} else {
			if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
				char c = static_cast<char>(value);
				if (std::isprint(c)) {
					std::cout << "char: '" << c << "'" << std::endl;
				} else {
					std::cout << "char: Non displayable" << std::endl;
				}
			} else {
				std::cout << "char: impossible" << std::endl;
			}

			if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
				std::cout << "int: " << static_cast<int>(value) << std::endl;
			} else {
				std::cout << "int: impossible" << std::endl;
			}

			if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
				std::cout << "float: impossible" << std::endl;
			} else {
				if (value == static_cast<int>(value)) {
					std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
					std::cout << "double: " << value << ".0" << std::endl;
				} else {
					std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
					std::cout << "double: " << value << std::endl;
				}
			}
		}
	} else if (type == CHAR) {
		if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
			char c = input[1];
			if (std::isprint(c)) {
				std::cout << "char: '" << c << "'" << std::endl;
			} else {
				std::cout << "char: Non displayable" << std::endl;
			}
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		} else if (input.length() == 1) {
			char c = input[0];
			if (std::isprint(c)) {
				std::cout << "char: '" << c << "'" << std::endl;
			} else {
				std::cout << "char: Non displayable" << std::endl;
			}
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
	} else if (type == INT) {
		char* end;
		errno = 0;
		long value = ::strtol(input.c_str(), &end, 10);

		if (errno == ERANGE || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}

		int intValue = static_cast<int>(value);
		if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max()) {
			char c = static_cast<char>(intValue);
			if (std::isprint(c)) {
				std::cout << "char: '" << c << "'" << std::endl;
			} else {
				std::cout << "char: Non displayable" << std::endl;
			}
		} else {
			std::cout << "char: impossible" << std::endl;
		}
		std::cout << "int: " << intValue << std::endl;

		if (intValue > std::numeric_limits<float>::max() || intValue < -std::numeric_limits<float>::max()) {
			std::cout << "float: impossible" << std::endl;
		} else {
			if (intValue == static_cast<int>(static_cast<float>(intValue))) {
				std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
			} else {
				std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl;
			}
		}
		if (intValue > std::numeric_limits<double>::max() || intValue < -std::numeric_limits<double>::max()) {
			std::cout << "double: impossible" << std::endl;
		} else {
			if (intValue == static_cast<int>(static_cast<double>(intValue))) {
				std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
			} else {
				std::cout << "double: " << static_cast<double>(intValue) << std::endl;
			}
		}
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

/*if (errno == ERANGE) {
    if (value == LONG_MAX) {
        std::cout << "Value exceeds LONG_MAX." << std::endl;
    } else if (value == LONG_MIN) {
        std::cout << "Value below LONG_MIN." << std::endl;
    }
}*/