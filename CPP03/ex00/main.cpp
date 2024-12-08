#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot1("Clappy");

	robot1.attack("Target1");

	robot1.takeDamage(3);
	robot1.beRepaired(5);
	robot1.beRepaired(10);

	for (int i = 0; i < 10; ++i)
	{
		robot1.attack("Target2");
	}

	robot1.attack("Target3"); // Не может атаковать из-за отсутствия энергии

	// Попытка ремонта без энергии
	robot1.beRepaired(5); 

	//Полное уничтожение (здоровье = 0)
	robot1.takeDamage(100);
	robot1.attack("Target4");
	robot1.beRepaired(5);

	ClapTrap robot2(robot1);
	robot2.attack("Target5");

	ClapTrap robot3("Dummy");
	robot3 = robot1;
	robot3.attack("Target6");

	return 0;
}
