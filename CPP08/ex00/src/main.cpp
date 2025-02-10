#include "easyfind.hpp"

int main() {

	int arr[] = {10, 20, 30, 40};
	std::vector<int> numbers(arr, arr + sizeof(arr)/sizeof(int));

	// or
	// std::vector<int> numbers;
	// for (int i = 10; i < 100; ++i)
	// {
	// 	numbers.push_back(i);
	// }

	std::cout << "------------" << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(numbers, 30);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------" << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(numbers, 50);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------" << std::endl;
	return 0;
}

// int main()
// {
// 	char arr1[] = {'a', 'b', 'c', 'd'};
// 	std::vector<char> char_array(arr1, arr1 + sizeof(arr));

// 	try {
// 		std::vector<char>::iterator it = easyfind(char_array, 'a');
// 		std::cout << "Found: " << *it << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	try {
// 		std::vector<char>::iterator it = easyfind(char_array, 't');
// 		std::cout << "Found: " << *it << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return 0
// }
