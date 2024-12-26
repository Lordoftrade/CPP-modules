#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

AForm::AForm() : _name("Default Form"), _isSigned(false), _requiredGradeToSign(150), _requiredGradeToExecute(150) {
	std::cout << "Form: " << getName() << " Constructor created with parameters -  GradeToSign: 150, GradeToExecute: 150" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _requiredGradeToSign(gradeToSign), _requiredGradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form: " << getName() << " Constructor created with parameters - GradeToSign: " 
			<< getRequiredGradeToSign() << ", GradeToExecute: " << getRequiredGradeToExecute() << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned),
	_requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute)
	{*this = other; std::cout << "Form copied\n";}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
		//_isSigned = false;
		//nothing;
	}
	std::cout << "Form assigned\n";
	return *this;
}

AForm::~AForm() {
	std::cout << "Form Deconstructor for " << getName() << " called" << std::endl;
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getRequiredGradeToSign() const {
	return _requiredGradeToSign;
}

int AForm::getRequiredGradeToExecute() const {
	return _requiredGradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout <<  "Form: " << getName() << " is signed by a bureaucrat " << bureaucrat.getName() << std::endl;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getRequiredGradeToExecute())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << "Form: " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", grade required to sign: " << form.getRequiredGradeToSign()
		<< ", grade required to execute: " << form.getRequiredGradeToExecute();
	return out;
}