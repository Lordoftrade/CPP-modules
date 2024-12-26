#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form) {
			Bureaucrat john("John", 45);
			john.signForm(*form);
			john.executeForm(*form);
			delete form;
		}

		form = someRandomIntern.makeForm("unknown form", "SomeTarget");
		delete form;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	// try {
	// 	Intern intern;
	// 	Bureaucrat bureaucrat("Alice", 1);

	// 	// ShrubberyCreationForm
	// 	AForm* shrubberyForm = intern.makeForm("shrubbery creation", "home");
	// 	std::cout << *shrubberyForm << std::endl;
	// 	bureaucrat.signForm(*shrubberyForm);
	// 	bureaucrat.executeForm(*shrubberyForm);
	// 	delete shrubberyForm;

	// 	// RobotomyRequestForm
	// 	AForm* robotomyForm = intern.makeForm("robotomy request", "Bender");
	// 	std::cout << *robotomyForm << std::endl;
	// 	bureaucrat.signForm(*robotomyForm);
	// 	bureaucrat.executeForm(*robotomyForm);
	// 	delete robotomyForm;

	// 	// PresidentialPardonForm
	// 	AForm* pardonForm = intern.makeForm("presidential pardon", "Ford Prefect");
	// 	std::cout << *pardonForm << std::endl;
	// 	bureaucrat.signForm(*pardonForm);
	// 	bureaucrat.executeForm(*pardonForm);
	// 	delete pardonForm;

	// 	// failure
	// 	AForm* invalidForm = intern.makeForm("invalid form", "test");
	// 	delete invalidForm; // Этот код никогда не выполнится
	// } catch (const std::exception& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }

	return 0;
}
