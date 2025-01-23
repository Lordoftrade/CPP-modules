#include "Base.hpp"

int main() {
	Base* randomObject = generate();

	std::cout << "Identifying by pointer:" << std::endl;
	identify(randomObject);

	std::cout << "Identifying by reference:" << std::endl;
	if (randomObject) {
		identify(*randomObject);
	} else {
		std::cout << "Null object, cannot identify" << std::endl;
	}

	delete randomObject;
	std::cout << "-------------" << std::endl;
	std::cout << "null pointer:" << std::endl;
	std::cout << "-------------" << std::endl;

	Base* nullPtr = NULL;
	std::cout << "Test with null pointer:" << std::endl;
	identify(nullPtr);

	return 0;
}