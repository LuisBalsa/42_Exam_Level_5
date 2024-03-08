#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell*> spells;

		SpellBook(SpellBook const &other);
		SpellBook &operator=(SpellBook const &other);

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell const *spell);
		void forgetSpell(std::string spell);
		ASpell* createSpell(std::string const &spell);
};
