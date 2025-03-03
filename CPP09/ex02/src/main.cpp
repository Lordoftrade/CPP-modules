#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: No numbers provided.\n";
		return 1;
	}

	PmergeMe sorter;
	sorter.parseArguments(argc, argv);

	sorter.printResults(true, sorter.getVector());
	sorter.sortAndMeasure(); 

	return 0;
}