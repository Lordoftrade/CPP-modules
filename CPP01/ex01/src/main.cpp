#include "Zombie.hpp"

int main()
{
	int N = 7;
	std::string name = "Foo";
	Zombie* horde = zombieHorde(N, name);
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete[] horde;

	return (0);
}