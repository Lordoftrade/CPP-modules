#include "Contact.hpp"
#include <iostream>
#include <iomanip> 
#include <cctype>

void Contact::setContact()
{
	bool isValid = false;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);

	while (!isValid)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);

		isValid = true;

		for (size_t i = 0; i < phoneNumber.length(); i++)
		{
			if (!std::isdigit(phoneNumber[i])) {
				isValid = false;
				std::cout << "Invalid phone number! Please enter only digits." << std::endl;
				break;
			}
		}
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
}

void Contact::displayContactSummary(int index) const
{
	std::cout << std::right << std::setw(10) << index << "|";

	if (firstName.length() > 10)
		std::cout << std::setw(10) << firstName.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << firstName << "|";

	if (lastName.length() > 10)
		std::cout << std::setw(10) << lastName.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << lastName << "|";


	if (nickname.length() > 10)
		std::cout << std::setw(10) << nickname.substr(0, 9) + "." << std::endl;
	else
		std::cout << std::setw(10) << nickname << std::endl;
}

void Contact::displayContactDetails() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}