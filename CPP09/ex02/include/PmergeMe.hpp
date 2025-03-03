#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>

class PmergeMe {
	private:
		std::vector<int> vec;
		std::deque<int> deq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void parseArguments(int argc, char **argv);
		void sortAndMeasure();
		void printResults(bool before) const;

	private:
		void fordJohnsonSort(std::vector<int> &container);
		void fordJohnsonSort(std::deque<int> &container);
		
		template <typename T>
		void mergeInsertionSort(T &container);

		double getTime();
};

#endif
