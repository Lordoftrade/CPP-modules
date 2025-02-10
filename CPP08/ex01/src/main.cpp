#include "Span.hpp"

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		//sp.addNumber(100);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Span sp2(10000);
		std::vector<int> bigData(10000);
		for (int i = 0; i < 10000; ++i) {
			bigData[i] = i * 2;
		}
		sp2.addNumbers(bigData.begin(), bigData.end());
		std::cout << "Big Data - Shortest Span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Big Data - Longest Span: " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
