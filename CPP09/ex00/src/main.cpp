#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>

std::string trim(const std::string &str) {
	std::string resalt;
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos) return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	if (!std::isdigit(year[0]) || !std::isdigit(year[1]) ||
		!std::isdigit(year[2]) || !std::isdigit(year[3]) ||
		!std::isdigit(month[0]) || !std::isdigit(month[1]) ||
		!std::isdigit(day[0]) || !std::isdigit(day[1]))
		return false;

	int y = atoi(year.c_str());
	int m = atoi(month.c_str());
	int d = atoi(day.c_str());

	if (m < 1 || m > 12) return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m == 2 && isLeapYear(y)) daysInMonth[1] = 29;

	if (d < 1 || d > daysInMonth[m - 1]) return false;
	return true;
}

bool isValidNumber(const std::string &str) {
	bool hasDot = false;
	bool hasMinus = false;
	if (str.empty()) return false;
	if (str[0] == '.') return false;

	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			if (i != 0 || hasMinus) return false;
			hasMinus = true;
		}
		else if (str[i] == '.') {
			if (hasDot) return false;
			hasDot = true;
		}
		else if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	if (argc != 2 ) {
		std::cerr << "Mistake: specify the input data file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.loadCSV("data.csv");

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << "Error: The file could not be opened - " << argv[1]  << std::endl;
		return 1;
	}

	std::string line;
	if (std::getline(inputFile, line)) {
		line = trim(line);
		if (line != "date | value") {
			std::cerr << "Error: incorrect header => There must be a 'date | value'" << std::endl;
			return 1;
		}
	}
	
	while (std::getline(inputFile, line)) {
		line = trim(line);
		if (line.empty()) continue;
		std::stringstream ss(line);
		std::string date, valueStr;
		double value;
	
		if (std::getline(ss, date, '|') && std::getline(ss >> std::ws, valueStr)) {
			date.erase(date.find_last_not_of(" \t\r\n") + 1);
			if (!isValidDate(date)) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			valueStr.erase(valueStr.find_last_not_of(" \t\r\n") + 1);

			if (valueStr == "-" || valueStr.empty() || valueStr == ".") { 
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			if (!isValidNumber(valueStr)) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			std::stringstream valueStream(valueStr);
			valueStream >> value;
			if (value < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			double rate = btc.getRate(date);
			if (rate != -1) {
				std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
			}
		}
		else {
			std::cerr << "Error: Incorrect string format => " << line << std::endl;
		}
	}
	inputFile.close();
	return 0;
}