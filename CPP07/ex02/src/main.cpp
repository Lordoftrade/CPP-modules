#include "Array.hpp"

int main() {

	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

	Array<int> intArray(5);
	std::cout << "Int array size: " << intArray.size() << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i * 10;
	}

	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}

	Array<int> copyArray(intArray);
	std::cout << "Copy array size: " << copyArray.size() << std::endl;
	for (unsigned int i = 0; i < copyArray.size(); i++) {
		std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
	}

	Array<int> assignedArray;
	assignedArray = intArray;
	std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
	for (unsigned int i = 0; i < assignedArray.size(); i++) {
		std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
	}


	try {
		std::cout << intArray[10] << std::endl; // Ошибка
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
