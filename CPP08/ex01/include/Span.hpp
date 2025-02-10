#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstddef>

class Span {
	private:
		unsigned int _num;
		std::vector<int> _numbers;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan() const;
		int longestSpan() const;
};

#endif

