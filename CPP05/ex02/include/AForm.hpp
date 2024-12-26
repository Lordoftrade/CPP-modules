#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm {
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
		class FormNotSignedException : public std::exception {
			public:
				/*virtual*/ const char* what() const throw();
		};

		/*
		class GradeTooHighException;
		class GradeTooLowException;
		class FormNotSignedException;
		*/

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

	public:
		const std::string& getName() const;
		bool isSigned() const;
		int getRequiredGradeToSign() const;
		int getRequiredGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
	public:
		virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif