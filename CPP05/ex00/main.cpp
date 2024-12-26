#include "Bureaucrat.hpp"

int main() {
	try
	{
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << b1 << std::endl;

		b1.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;

		b2.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Charlie", 200);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
