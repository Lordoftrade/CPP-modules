#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 150);

		Form testForm("Test Form", 100, 50);

		std::cout << testForm << std::endl;

		bob.signForm(testForm);
		std::cout << testForm << std::endl;

		alice.signForm(testForm);
		std::cout << testForm << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
