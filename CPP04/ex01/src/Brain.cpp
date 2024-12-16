#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = "Default idea"; 
	}
	std::cout << "Brain created\n";
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = other.ideas[i]; 
	}
	//*this = other;
	std::cout << "Brain copied\n";
}

Brain& Brain::operator=(const Brain& other)
{
	if (this == &other) {return *this;}
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = other.ideas[i]; 
	}
	std::cout << "Brain assigned\n";
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed\n";
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100) {
		return ideas[index];
	}
	return "";
}