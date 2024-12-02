#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "Debugging the issue: everything looks fine so far." << std::endl;
}
void Harl::info( void ){
	std::cout << "Here is some information: the system is running smoothly." << std::endl;
}

void Harl::warning( void ){
	std::cout << "Warning: something might go wrong, please check it!" << std::endl;
}

void Harl::error( void ){
	std::cout << "Error: something went wrong, immediate action is required!" << std::endl;
}

void Harl::complain(const std::string level ){
	void (Harl::*methodFunc[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*methodFunc[i])();
			return ;
		}
	}
	std::cout << "Invalid level: " << level << std::endl;
}
