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

const std::vector<int> &PmergeMe::getVector() const {
	return vec;
}

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
	printResults(false, vec);
	std::cout << "Time to process a range of " << vec.size()
				<< " elements with std::vector: " << std::fixed << std::setprecision(5) << (end - start) / 1000000.0 << " us\n";
	start = getTime();
	fordJohnsonSort(deq);
	end = getTime();
	std::cout << "Time to process a range of " << deq.size()
				<< " elements with std::deque: " << std::fixed << std::setprecision(5) << (end - start) / 1000000.0 << " us\n";
}

void PmergeMe::printResults(bool before, const std::vector<int> &container) const {
	std::cout << (before ? "Before: " : "After: ");
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
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

std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (jacobsthal.back() < static_cast<int>(size)) {
		jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
	}
	return jacobsthal;
}

template <typename T>
void PmergeMe::insertUsingJacobsthal(T &container, std::list<int> &remaining) {
    std::vector<int> jacobsthal = generateJacobsthalSequence(remaining.size());

    for (size_t i = 1; i < jacobsthal.size() && !remaining.empty(); ++i) {
        int index = jacobsthal[i];
        std::list<int>::iterator it = remaining.begin();

        if (index >= static_cast<int>(remaining.size())) {
            index = remaining.size() - 1;
        }
        
        std::advance(it, index);
        container.insert(std::upper_bound(container.begin(), container.end(), *it), *it);
        remaining.erase(it);

		std::cout << "После вставки " << *it << ":\n";
        std::cout << "Big Elements: ";
        for (size_t num : container) std::cout << num << " ";
        std::cout << "\nRemaining: ";
        for (int num : remaining) std::cout << num << " ";
        std::cout << "\n";
    }

    while (!remaining.empty()) {
        int value = remaining.front();
        container.insert(std::upper_bound(container.begin(), container.end(), value), value);
        remaining.pop_front();

		std::cout << "После вставки " << value << ":\n";
        std::cout << "Big Elements: ";
        for (size_t num : container) std::cout << num << " ";
        std::cout << "\nRemaining: ";
        for (int num : remaining) std::cout << num << " ";
        std::cout << "\n";
    }
}


void PmergeMe::fordJohnsonSort(std::vector<int> &container) {
    std::vector<int> bigElements;
    std::list<int> remaining;

    for (size_t i = 0; i < container.size(); i += 2) {
        if (i + 1 < container.size()) {
            if (container[i] > container[i + 1]) {
                bigElements.push_back(container[i]);
                remaining.push_back(container[i + 1]);
            } else {
                bigElements.push_back(container[i + 1]);
                remaining.push_back(container[i]);
            }
        } else {
            remaining.push_back(container[i]);
        }
    }

	std::cout << "Big Elements: ";
    for (size_t num : bigElements) std::cout << num << " ";
    std::cout << "\nRemaining (меньшие): ";
    for (int num : remaining) std::cout << num << " ";
    std::cout << "\n";

    while (bigElements.size() > 1) {
        std::vector<int> newBigElements;

        for (size_t i = 0; i < bigElements.size(); i += 2) {
            if (i + 1 < bigElements.size()) {
                if (bigElements[i] > bigElements[i + 1]) {
                    newBigElements.push_back(bigElements[i]);
                    remaining.push_back(bigElements[i + 1]);
                } else {
                    newBigElements.push_back(bigElements[i + 1]);
                    remaining.push_back(bigElements[i]);
                }
            } else {
                newBigElements.push_back(bigElements[i]);
            }
        }
        bigElements = newBigElements;

		std::cout << "После разбиения: ";
		for (size_t num : bigElements) std::cout << num << " ";
		std::cout << "\nRemaining: ";
		for (int num : remaining) std::cout << num << " ";
		std::cout << "\n";
    }

	std::cout << "=== Перед сортировкой Merge-Insertion ===\n";
	std::cout << "Big Elements (до сортировки): ";
	for (size_t num : bigElements) std::cout << num << " ";
	std::cout << "\n";

    mergeInsertionSort(bigElements);

	std::cout << "Big Elements (после сортировки): ";
	for (size_t num : bigElements) std::cout << num << " ";
	std::cout << "\n";
	

	std::cout << "=== Начинаем вставку меньших элементов по Якобсталю ===\n";
	std::cout << "Big Elements (перед вставкой): ";
	for (size_t num : bigElements) std::cout << num << " ";
	std::cout << "\nRemaining: ";
	for (int num : remaining) std::cout << num << " ";
	std::cout << "\n";

    insertUsingJacobsthal(bigElements, remaining);

    container = bigElements;
}


void PmergeMe::fordJohnsonSort(std::deque<int> &container) {
    std::deque<int> bigElements;
    std::list<int> remaining;

    for (size_t i = 0; i < container.size(); i += 2) {
        if (i + 1 < container.size()) {
            if (container[i] > container[i + 1]) {
                bigElements.push_back(container[i]);
                remaining.push_back(container[i + 1]);
            } else {
                bigElements.push_back(container[i + 1]);
                remaining.push_back(container[i]);
            }
        } else {
            remaining.push_back(container[i]); 
        }
    }

    while (bigElements.size() > 1) {
        std::deque<int> newBigElements;

        for (size_t i = 0; i < bigElements.size(); i += 2) {
            if (i + 1 < bigElements.size()) {
                if (bigElements[i] > bigElements[i + 1]) {
                    newBigElements.push_back(bigElements[i]);
                    remaining.push_back(bigElements[i + 1]);
                } else {
                    newBigElements.push_back(bigElements[i + 1]);
                    remaining.push_back(bigElements[i]);
                }
            } else {
                newBigElements.push_back(bigElements[i]);
            }
        }
        bigElements = newBigElements;
    }

    mergeInsertionSort(bigElements);

    insertUsingJacobsthal(bigElements, remaining);

    container = bigElements;
}
