#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//Animal animal;
	//Animal* a = new Animal();
	

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " says: ";
	dog->makeSound();

	std::cout << cat->getType() << " says: ";
	cat->makeSound();

	delete dog;
	delete cat;
	return 0;
}
