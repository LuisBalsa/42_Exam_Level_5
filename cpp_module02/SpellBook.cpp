#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::SpellBook(SpellBook const &other) {*this = other;}
SpellBook &SpellBook::operator=(SpellBook const &other) {*this = other; return(*this);}

SpellBook::~SpellBook()
{
	for (auto it = spells.begin(); it != spells.end(); it++)
		delete it->second;
	spells.clear();
}
void SpellBook::learnSpell(ASpell const *spell)
{
	if (spell)
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string spell)
{
	if (spells.find(spell) != spells.end())
	{
		delete spells[spell];
		spells.erase(spell);
	}
}

ASpell *SpellBook::createSpell(std::string const &spell)
{
	if (spells.find(spell) != spells.end())
		return spells[spell]->clone();
	return NULL;
}

