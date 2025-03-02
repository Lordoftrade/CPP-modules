#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
	private:
		std::stack<int> stack;
		bool isOperator(char c);
		int applyOperator(int a, int b, char op);
	
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int evaluate(const std::string &expression);

};

#endif