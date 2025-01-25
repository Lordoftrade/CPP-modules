#include "iter.hpp"

int main(){

	int arr[4] = {1, 2, 3, 5};
	::iter(arr, 4, ::func<double>);

	std::string strings[] = {"Hello", "World", "C++", "is", "GOOD"};
	::iter(strings, 5, ::func);

	return 0;
}
