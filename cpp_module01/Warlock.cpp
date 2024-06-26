#include "Warlock.hpp"

Warlock::Warlock(){}

Warlock &Warlock::operator=(Warlock const &other)
{
	this->name = other.getName();
	this->title = other.getTitle();
	return (*this);
}

Warlock::Warlock(Warlock const &other)
{
	*this = other;
}

Warlock::Warlock(std::string const name, std::string const title) : name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	spells.clear();
}

std::string const Warlock::getName() const
{
	return (this->name);
}

std::string const Warlock::getTitle() const
{
	return (this->title);
}

void	Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am "  << this->name << ", "  << this->title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell;
}

void	Warlock::forgetSpell(std::string const &spell)
{
	if (spells.find(spell) != spells.end())
		spells.erase(spell);
}

void	Warlock::launchSpell(std::string const &spell, ATarget &target)
{
	if (spells.find(spell) != spells.end())
		spells[spell]->launch(target);
}

