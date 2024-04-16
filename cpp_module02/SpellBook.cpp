#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook &SpellBook::operator=(SpellBook const &other)
{
	if (this == &other);
		return (*this);
	return (*this);
}

SpellBook::SpellBook(SpellBook const &other)
{
	*this = other;
}
SpellBook::~SpellBook()
{
	spells.clear();
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell;
}

void	SpellBook::forgetSpell(std::string const &spell)
{
	if (spells.find(spell) != spells.end())
		spells.erase(spell);
}

ASpell	*SpellBook::createSpell(std::string const &spell)
{
	if (spells.find(spell) != spells.end())
		return (spells[spell]);
	return (NULL);
}
