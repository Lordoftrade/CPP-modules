#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon default form", 25, 5), _target("default target")
{
	std::cout << "PresidentialPardonForm " << getName() << " Constructor created with parameters - GradeToSign: " 
			<< getRequiredGradeToSign() << ", GradeToExecute: " << getRequiredGradeToExecute() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm created for target: " << _target << " with parameters - GradeToSign: " 
			<< getRequiredGradeToSign() << ", GradeToExecute: " << getRequiredGradeToExecute() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm copied from " << other.getName() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assign)
{
	if (this != &assign) {
		AForm::operator=(assign);
		//this->_target = assign._target;
		// _target const его нельзя изменить
		std::cerr << "Cannot reassign target of PresidentialPardonForm" << std::endl;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << getName() << " destroyed" << std::endl;
}


void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}