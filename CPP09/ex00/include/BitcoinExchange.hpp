#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <cmath>

class BitcoinExchange {
	private:
		std::map<std::string, double> btcRates;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadCSV(const std::string &filename);
		double getRate(const std::string &date) const;
};

#endif

