#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
	private:
		Contact contacts[8];
		int 	contactCount;
		int		 oldestIndex;

	public:
		Phonebook();
		void addContact();
		void searchContact() const;
};

#endif