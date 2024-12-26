#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy default form", 72, 45), _target("default target")
{
	std::cout << "RobotomyRequestForm " << getName() << " Constructor created with parameters - GradeToSign: "
			<< getRequiredGradeToSign() << ", GradeToExecute: " << getRequiredGradeToExecute() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy form", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm created for target: " << _target << " with parameters - GradeToSign: "
			<< getRequiredGradeToSign() << ", GradeToExecute: " << getRequiredGradeToExecute() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copied from " << other.getName() << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& assign)
{
	if (this != &assign) {
		AForm::operator=(assign);
		//this->_target = assign._target;
		// _target const его нельзя изменить
		std::cerr << "Cannot reassign target of RobotomyRequestForm" << std::endl;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << getName() << " destroyed" << std::endl;
}


void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::cout << "* Drilling noises *" << std::endl;

	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << "!!!" << std::endl;
}
