
#include "Zombie.hpp"

int main()
{
	Zombie* allocZombie = newZombie("Foo_heap");
	allocZombie->announce();
	delete allocZombie;

	randomChump("Foo_stack");
	return (0);
}