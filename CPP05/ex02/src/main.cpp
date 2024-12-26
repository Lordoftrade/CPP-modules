#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try {
        Bureaucrat john("John", 2);
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Target");
        PresidentialPardonForm pardon("Criminal");

        std::cout << shrubbery << std::endl;
        john.signForm(shrubbery);
        john.executeForm(shrubbery);

        std::cout << robotomy << std::endl;
        john.signForm(robotomy);
        john.executeForm(robotomy);

        std::cout << pardon << std::endl;
        john.signForm(pardon);
        john.executeForm(pardon);
    }
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
