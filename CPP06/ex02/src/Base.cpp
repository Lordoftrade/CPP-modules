#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
	cout << "Base destructor\n";
}

Base* generate() {

	srand(time(0));

	int random = rand() % 3;

	if (random == 0) {
		cout << "Generated: A" << std::endl;
		return new A();
	} else if (random == 1) {
		cout << "Generated: B" << std::endl;
		return new B();
	} else {
		cout << "Generated: C" << std::endl;
		return new C();
	}
}
void	identify( Base *p )
{
	if (!p) {
		std::cout << "Null pointer, cannot identify type" << std::endl;
		return;
	}

	if (dynamic_cast<A*>(p)) {
		std::cout << "Object identified as *A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Object identified as *B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Object identified as *C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {

	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "Object identified as &A" << std::endl;
		(void)a;
		return;
	} catch (const std::exception& e) {
		cout << "Not of type A! " << "exception: " << e.what() << std::endl;
	}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "Object identified as &B" << std::endl;
		(void)b;
		return;
	} catch (const std::exception& e) {
		cout << "Not of type B! " << "exception: " << e.what() << std::endl;
	}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "Object identified as &C" << std::endl;
		(void)c;
		return;
	} catch (const std::exception& e) {
		cout << "Not of type C! " << "exception: " << e.what() << std::endl;
	}

	std::cout << "Unknown type" << std::endl;
}