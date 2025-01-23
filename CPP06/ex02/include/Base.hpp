#ifndef BASE_HPP
#define BASE_HPP

#include <ctime>
#include <iostream>
#include <exception>
// #include <typeinfo> 
#include <cstdlib>

using std::endl;
using std::cout;

class Base {
	public:
		virtual ~Base();
};

Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );


#endif