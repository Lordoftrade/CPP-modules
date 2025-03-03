/* ************************************************************************** */
/*                                                                            */
/*                            PmergeMe.cpp                                    */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArguments(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);
		if (num <= 0) {
			std::cerr << "Error: Invalid input " << argv[i] << "\n";
			exit(1);
		}
		vec.push_back(num);
		deq.push_back(num);
	}
}

void PmergeMe::sortAndMeasure() {
	double start, end;

	start = getTime();
	fordJohnsonSort(vec);
	end = getTime();
	std::cout << "Time to process a range of " << vec.size()
				<< " elements with std::vector: " << std::fixed << std::setprecision(5) << (end - start) / 1000000.0 << " us\n";
	start = getTime();
	fordJohnsonSort(deq);
	end = getTime();
	std::cout << "Time to process a range of " << deq.size()
				<< " elements with std::deque: " << std::fixed << std::setprecision(5) << (end - start) / 1000000.0 << " us\n";
}

void PmergeMe::printResults(bool before) const {
	std::cout << (before ? "Before: " : "After: ");
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << "\n";
}

double PmergeMe::getTime() {
	struct timeval time;
	gettimeofday(&time, NULL);
	return time.tv_sec * 1000000 + time.tv_usec;
}

template <typename T>
void PmergeMe::mergeInsertionSort(T &container) {
	if (container.size() < 2) return;

	size_t mid = container.size() / 2;
	T left(container.begin(), container.begin() + mid);
	T right(container.begin() + mid, container.end());

	mergeInsertionSort(left);
	mergeInsertionSort(right);

	container.clear();
	typename T::iterator itLeft = left.begin(), itRight = right.begin();
	while (itLeft != left.end() && itRight != right.end()) {
		if (*itLeft < *itRight) container.push_back(*itLeft++);
		else container.push_back(*itRight++);
	}
	container.insert(container.end(), itLeft, left.end());
	container.insert(container.end(), itRight, right.end());
}

void PmergeMe::fordJohnsonSort(std::vector<int> &container) {
	mergeInsertionSort(container);
}

void PmergeMe::fordJohnsonSort(std::deque<int> &container) {
	mergeInsertionSort(container);
}
