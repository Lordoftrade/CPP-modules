#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
	
		void setContact();
		void displayContactSummary(int index) const;
		void displayContactDetails() const;
};

#endif