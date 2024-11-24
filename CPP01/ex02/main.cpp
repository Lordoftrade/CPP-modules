#include <iostream>
#include <string>

int main()
{
	std::string value = "HI THIS IS BRAIN";
	std::string *valuePTR = &value;
	std::string &valueREF = value;

	std::cout << "Memory address of the string value: " << &value << std::endl;
	std::cout << "Memory address held by valuePTR: " << valuePTR << std::endl;
	std::cout << "Memory address held by valueREF: " << &valueREF << std::endl;

	std::cout << "Value of the string value: " << value << std::endl;
	std::cout << "Value pointed to by valuePTR: "<< *valuePTR << std::endl;
	std::cout << "Value pointed to by valueREF.: " << valueREF << std::endl;
	return (0);
}