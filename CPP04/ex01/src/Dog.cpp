#include "Dog.hpp"

Dog::Dog() 
	: Animal(), brain(new Brain())
{
	this->type = "Dog";
	//this->brain = new Brain();
	std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other) {return *this;}
	type = other.type;

	delete brain;
	brain = new Brain();
	for (int i = 0; i < 100; ++i)
	{
		this->brain->setIdea(i, other.brain->getIdea(i)); 
	}
	std::cout << "Dog copy assignment operator" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destroyed\n";
}
void Dog::makeSound() const
{
	std::cout << "Woof! Woof!\n";
}

void Dog::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}


