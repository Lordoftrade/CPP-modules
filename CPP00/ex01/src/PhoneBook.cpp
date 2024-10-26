#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits> 
#include <string>
#include <string>
#include "Contact.hpp"
#include <iostream>
#include <iomanip> 
#include <cctype>
#include <cstdlib>

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
    if (contactCount == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << std::right << std::setw(10) << "Index" << "|";
    std::cout << std::right << std::setw(10) << "First Name" << "|";
    std::cout << std::right << std::setw(10) << "Last Name" << "|";
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        contacts[i].displayContactSummary(i);
    }

    std::string index;
    int index_num;

    while (true) {
        std::cout << "Enter index to view details: ";
        std::getline(std::cin, index);

        bool isNumber = true;
        for (size_t i = 0; i < index.length(); i++) {
            if (!std::isdigit(index[i])) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber || index.empty()) {
            std::cout << "Invalid number! Please enter only digits." << std::endl;
            continue; 
        }

        index_num = std::atoi(index.c_str());

        if (index_num >= 0 && index_num < contactCount) {
            break; 
        } else {
            std::cout << "Invalid index! Please enter a valid index between 0 and " << (contactCount - 1) << "." << std::endl;
        }
    }

    contacts[index_num].displayContactDetails();
}


