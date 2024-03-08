#include "Warlock.hpp"

Warlock::Warlock() {}
Warlock::Warlock(Warlock const &other) {*this = other;}
Warlock &Warlock::operator=(Warlock const &other) {*this = other; return(*this);}

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	for (auto it = spells.begin(); it != spells.end(); it++)
		delete it->second;
	spells.clear();
}

std::string const &Warlock::getName() const
{
	return(this->name);
}

std::string const &Warlock::getTitle() const
{
	return(this->title);
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell const *spell)
{
	if (spell)
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spell)
{
	if (spells.find(spell) != spells.end())
	{
		delete spells[spell];
		spells.erase(spell);
	}
}

void Warlock::launchSpell(std::string spell, ATarget const &target)
{
	if (spells.find(spell) != spells.end())
		spells[spell]->launch(target);
}
