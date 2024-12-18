#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//std::cout << "\n--- Тест 1: Создание массива животных и удаление животных ---\n";
	const int numAnimals = 6;
	const Animal* animals[numAnimals];

	for (int i = 0; i < numAnimals / 2; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = numAnimals / 2; i < numAnimals; ++i)
	{
		animals[i] = new Cat();
	}
	for (int i = 0; i < numAnimals; ++i)
	{
		animals[i]->makeSound();
	}
	for (int i = 0; i < numAnimals; ++i)
	{
		delete animals[i];
	}

	//std::cout << "\n--- Тест 2: Копирование Cat ---\n";
	Cat originalCat;
	originalCat.makeSound();
	originalCat.setIdea(0, "Catch a mouse");
	std::cout << "Original Cat's first idea: " << originalCat.getIdea(0) << std::endl;

	Cat copiedCat(originalCat);
	std::cout << "Copied Cat's first idea: " << copiedCat.getIdea(0) << std::endl;
	copiedCat.setIdea(0, "Sleep all day");
	std::cout << "Modified Copied Cat's first idea: " << copiedCat.getIdea(0) << std::endl;
	std::cout << "Original Cat's first idea after modification: " << originalCat.getIdea(0) << std::endl;

	//std::cout << "\n--- Тест 3: Копирование Dog ---\n";
	Dog originalDog;
	originalDog.makeSound();
	originalDog.setIdea(0, "Chase a ball");
	std::cout << "Original Dog's first idea: " << originalDog.getIdea(0) << std::endl;

	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << "Assigned Dog's first idea: " << assignedDog.getIdea(0) << std::endl;

	assignedDog.setIdea(0, "Bark at strangers");
	std::cout << "Modified Assigned Dog's first idea: " << assignedDog.getIdea(0) << std::endl;
	std::cout << "Original Dog's first idea after modification: " << originalDog.getIdea(0) << std::endl;

	//std::cout << "\n--- Финиш ---\n";

	return 0;
}
