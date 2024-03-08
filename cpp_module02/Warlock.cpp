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
	spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spell)
{
	spellBook.forgetSpell(spell);
}

void Warlock::launchSpell(std::string spell, ATarget &target)
{
	ASpell *newSpell = spellBook.createSpell(spell);
	if (newSpell)
	{
		newSpell->launch(target);
		delete newSpell;
	}
}
