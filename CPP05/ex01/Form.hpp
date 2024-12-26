#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _requiredGradeToSign;
		const int _requiredGradeToExecute;

	public:
		class GradeTooHighException : public std::exception {
			public:
				/*virtual*/ const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				/*virtual*/ const char* what() const throw();
		};

		/*
		class GradeTooHighException;
		class GradeTooLowException;
		*/

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

	public:
		const std::string& getName() const;
		bool isSigned() const;
		int getRequiredGradeToSign() const;
		int getRequiredGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif