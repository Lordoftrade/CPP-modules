#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

/*
class Form::GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Grade too high"); }
};

class Form::GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Grade too low"); }
};
*/

Form::Form() : _name("Default Form"), _isSigned(false), _requiredGradeToSign(150), _requiredGradeToExecute(150) {
	std::cout << "Form: " << getName() << " Constructor created with parameters -  GradeToSign: 150, GradeToExecute: 150" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _requiredGradeToSign(gradeToSign), _requiredGradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form: " << getName() << " Constructor created with parameters - GradeToSign: "
			<< getRequiredGradeToSign() << ", GradeToExecute: " << getRequiredGradeToExecute() << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned),
	_requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute)
	{*this = other; std::cout << "Form copied\n";}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
		//_isSigned = false;
		//nothing;
	}
	std::cout << "Form assigned\n";
	return *this;
}

Form::~Form() {
	std::cout << "Form Deconstructor for " << getName() << " called" << std::endl;
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getRequiredGradeToSign() const {
	return _requiredGradeToSign;
}

int Form::getRequiredGradeToExecute() const {
	return _requiredGradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout <<  "Form: " << getName() << " is signed by a bureaucrat " << bureaucrat.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form: " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", grade required to sign: " << form.getRequiredGradeToSign()
		<< ", grade required to execute: " << form.getRequiredGradeToExecute();
	return out;
}
