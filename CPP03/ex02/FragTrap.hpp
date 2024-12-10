#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& another);
		FragTrap& operator=(const FragTrap& another);
		~FragTrap();

		void highFivesGuys(void);
};

#endif