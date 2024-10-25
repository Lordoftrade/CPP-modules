
#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>


std::string toUpperCase(const std::string& str)
{
	std::string upperStr = str;

	for (size_t i = 0; i < upperStr.length(); ++i)
	{
		upperStr[i] = std::toupper(upperStr[i]);
	}
	return (upperStr);
}

int main() 
{
	Phonebook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		
		command = toUpperCase(command);
		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}
	return 0;
}