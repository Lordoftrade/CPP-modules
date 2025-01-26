#include "iter.hpp"

int main(){

	std::cout << "=== Test 1: int array with print ===" << std::endl;
	int arr[4] = {1, 2, 3, 5};
	::iter(arr, 4, ::func);

	std::cout << "=== Test 2: int array with print ===" << std::endl;
	std::string strings[] = {"Hello", "World", "C++", "is", "GOOD"};
	::iter(strings, 5, ::func);

	std::cout << "=== Test 3: Double array with print ===" << std::endl;
	double arr2[4] = {1.1, 2.2, 3.3, 4.4};
	::iter(arr2, 4, ::func<float>);

	return 0;
}
