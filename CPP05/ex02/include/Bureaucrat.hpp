#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

	public:
		const std::string& getName(void) const;
		int getGrade(void) const;

	public:
		void incrementGrade();
		void decrementGrade();

	public:
		void signForm(AForm& form);
		void executeForm(const AForm& form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
