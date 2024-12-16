#include "Cat.hpp"

Cat::Cat() 
	: Animal(), brain(new Brain())
{
	this->type = "Cat";
	//this->brain = new Brain();
	std::cout << "Cat created\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other) {return *this;}
	this->type = other.type;

	delete brain;
	brain = new Brain();
	for (int i = 0; i < 100; ++i)
	{
		this->brain->setIdea(i, other.brain->getIdea(i)); 
	}
	std::cout << "Cat assigned\n";
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!\n";
}

void Cat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}