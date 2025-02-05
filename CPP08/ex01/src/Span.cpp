#include "Span.hpp"

Span::Span() : _num(0) {}

Span::Span(unsigned int N) : _num(N) {}

Span::Span(const Span& other) : _num(other._num), _numbers(other._numbers) {}

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		this->_num = other._num;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_numbers.size() >= _num)
		throw std::runtime_error("Span is full!");
	_numbers.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if ((_numbers.size() + std::distance(begin, end)) > _num)
		throw std::runtime_error("Not enough space in Span!");
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a shortestSpan!");
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); ++i) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a longesSpan!");
	}

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return (maxVal - minVal);

	// std::vector<int> sorted = _numbers;
	// std::sort(sorted.begin(), sorted.end());
	// return (sorted.back() - sorted.front());
}