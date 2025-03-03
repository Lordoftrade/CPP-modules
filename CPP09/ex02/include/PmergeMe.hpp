#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cstdlib>
#include <sys/time.h>
#include <algorithm>
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
		void printResults(bool before, const std::vector<int> &container) const;
		const std::vector<int> &getVector() const;

	private:
		void fordJohnsonSort(std::vector<int> &container);
		void fordJohnsonSort(std::deque<int> &container);
		
		template <typename T>
		void mergeInsertionSort(T &container);

		template <typename T>
		void insertUsingJacobsthal(T &container, std::list<int> &remaining);

		std::vector<int> generateJacobsthalSequence(size_t size);
		double getTime();
};

#endif
