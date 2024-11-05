#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

class Replace {
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		
		std::string replace_s1_to_s2(const std::string& line, const std::string& s1, const  std::string& s2) const;
	public:
		Replace(const std::string& line, const std::string& s1, const  std::string& s2);
		bool check_and_open() const;
};

#endif