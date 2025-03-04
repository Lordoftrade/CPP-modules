#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		btcRates = other.btcRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadCSV(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if(!file) {
		std::cerr << "Error: The file could not be opened - " << filename << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string priceStr;
		double price;

		if (std::getline(ss, date, ',') && std::getline(ss >> std::ws, priceStr)) {
			std::stringstream priceStream(priceStr);
			priceStream >> price;
			btcRates[date] = price;
		}
	}
	file.close();
}

double BitcoinExchange::getRate(const std::string &date) const {
	std::map<std::string, double>::const_iterator it = btcRates.lower_bound(date);
	if (it == btcRates.end() || it->first != date) {
		if (it == btcRates.begin()) {
			std::cerr << "Error: No historical data for this date." << std::endl;
			return -1;
		}
		--it;
	}
	return it->second;
}
