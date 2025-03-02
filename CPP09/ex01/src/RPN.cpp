#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->stack = other.stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(int a, int b, char op) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': 
			if (b == 0) 
				throw std::runtime_error("Division by zero");
			return a / b;
		default: throw std::runtime_error("Unknown operator");
	}
}

int RPN::evaluate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.size() == 1 && isdigit(token[0])) {
			stack.push(token[0] - '0');
		}
		else if (token.size() == 1 &&  isOperator(token[0])) {
			if (stack.size() < 2) {
				throw std::runtime_error("Error: Not enough operands");
			}
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			stack.push(applyOperator(a, b, token[0]));
		}
		else {
			throw std::runtime_error("Error: Invalid token");
		}	
	}
	if (stack.size() != 1) {
		throw std::runtime_error("Error: Too many operands");
	}
	return stack.top();
}



