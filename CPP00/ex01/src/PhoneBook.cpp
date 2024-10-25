#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits> 
#include <string>

void printGreenTextInBox(const std::string& text)
{
	const std::string green = "\033[32m";
	const std::string reset = "\033[0m";
    int textLength = text.length();

	std::string horizontalBorder = "+" + std::string(textLength + 2, '-') + "+";

	std::cout << horizontalBorder << std::endl;
	std::cout << "|" << green << " " << text << " " << reset << "|" << std::endl;
	std::cout << horizontalBorder << std::endl;
}

Phonebook::Phonebook() : contactCount(0), oldestIndex(0) {}

void Phonebook::addContact()
{
	if (contactCount < 8) {
		contacts[contactCount].setContact();
		contactCount++;
	} else
	{
		contacts[oldestIndex].setContact();
		oldestIndex = (oldestIndex + 1) % 8;
	}
	printGreenTextInBox("The contact was added successfully!");
}

void Phonebook::searchContact() const {
	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		contacts[i].displayContactSummary(i);
	}

	int index;
	std::cout << "Enter index to view details: ";
	std::cin >> index;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (index >= 0 && index < contactCount) {
		contacts[index].displayContactDetails();
	} else
	{
		std::cout << "Invalid index!" << std::endl;
	}
}


