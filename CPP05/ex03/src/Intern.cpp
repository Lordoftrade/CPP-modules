#include "Intern.hpp"

const char* Intern::CannotMakeFormIntern::what() const throw() {
	return "Intern cannot create the requested form. Form name not recognized.";
}

Intern::Intern() {
	std::cout << "Intern created." << std::endl;
}

Intern::Intern(const Intern& other) {
	//*this = other;
	(void)other;
	std::cout << "Intern copied." << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << "Intern assigned." << std::endl; 
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destroyed." << std::endl;
}

static AForm* makeShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* makePresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}



AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[3])(const std::string&) = {
		&makeShrubbery,
		&makeRobotomy,
		&makePresidential
	};
		//[](const std::string& target) { return new ShrubberyCreationForm(target); },
		//[](const std::string& target) { return new RobotomyRequestForm(target); },
		//[](const std::string& target) { return new PresidentialPardonForm(target); }
	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	throw CannotMakeFormIntern();
}