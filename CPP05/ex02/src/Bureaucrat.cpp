#include "Bureaucrat.hpp"
#include "AForm.hpp"


const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat " << getName() << " Constructor created with grade - " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(150) {
	std::cout << "Bureaucrat " << getName() << " Constructor created with grade - " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default"), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << getName() << " Constructor created with grade - " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
    if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << getName() << " Constructor created with grade - " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName() + "_copy"), _grade(other._grade) {
	//*this = other;
	std::cout << "Bureaucrat Copy Constructor called to copy " << other.getName() <<
	" into " << this->getName() << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Deconstructor for " << getName() << " called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat assigned" << std::endl;
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

/*friend 
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b._name << ", bureaucrat grade " << b._grade;
    return out;
}*/

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}