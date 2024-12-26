#include "ShrubberyCreationForm.hpp"

#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery default form", 145, 137), _target("default target")
{
	std::cout << "ShrubberyCreationForm " << getName() << " Constructor created with parameters - GradeToSign: " 
			<< getRequiredGradeToSign() << ", GradeToExecute: " << getRequiredGradeToExecute() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery form", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm created for target: " << _target << " with parameters - GradeToSign: " 
			<< getRequiredGradeToSign() << ", GradeToExecute: " << getRequiredGradeToExecute() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copied from " << other.getName() << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assign)
{
	if (this != &assign) {
		AForm::operator=(assign);
		//this->_target = assign._target;
		// _target const его нельзя изменить
		std::cerr << "Cannot reassign target of ShrubberyCreationForm" << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << getName() << " destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	//AForm::execute(executor);
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getRequiredGradeToExecute())
		throw GradeTooLowException();
	std::ofstream file((_target + "_shrubbery.txt").c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open file " + _target + "_shrubbery");
	
	file << "        *" << std::endl;
	file << "       /o\\" << std::endl;
	file << "      /ooo\\" << std::endl;
	file << "     /o   o\\" << std::endl;
	file << "    /ooo ooo\\" << std::endl;
	file << "   /  o   o  \\" << std::endl;
	file << "  / ooooo ooo \\" << std::endl;
	file << " /o    o   o   \\" << std::endl;
	file << "/____oooooo_____\\";
	
	std::cout << GREEN << "        *" << RESET << std::endl;
	std::cout << GREEN << "       /" << YELLOW << "o" << GREEN << "\\" << RESET << std::endl;
	std::cout << GREEN << "      /" << RED << "o" << YELLOW << "o" << RED << "o" << GREEN << "\\" << RESET << std::endl;
	std::cout << GREEN << "     /" << BLUE << "o" << GREEN << "   " << RED << "o" << GREEN << "\\" << RESET << std::endl;
	std::cout << GREEN << "    /" << RED << "o" << YELLOW << "o" << BLUE << "o " << RED << "o" << YELLOW << "o" << BLUE << "o" << GREEN << "\\" << RESET << std::endl;
	std::cout << GREEN << "   /  " << YELLOW << "o" << GREEN << "   " << RED << "o" << GREEN << "  \\" << RESET << std::endl;
	std::cout << GREEN << "  / " << BLUE << "o" << RED << "o" << YELLOW << "o" << YELLOW << "o " << RED << "o" << GREEN << "    \\" << RESET << std::endl;
	std::cout << GREEN << " /" << RED << "o" << GREEN << "    " << YELLOW << "o" << GREEN << "   " << RED << "o" << GREEN << "   \\" << RESET << std::endl;
	std::cout << GREEN << "/____" << BLUE << "o" << RED << "o" << YELLOW << "o" << BLUE << "o" << YELLOW << "o" << BLUE << "o" << GREEN << "_____\\" << RESET << std::endl;
	std::cout << GREEN << "      ||||" << RESET << std::endl;
	std::cout << GREEN << "      ||||" << RESET << std::endl;
	std::cout << GREEN << "      ||||" << RESET << std::endl;

	file.close();
	std::cout << "Shrubbery created for target: " << _target << std::endl;
}