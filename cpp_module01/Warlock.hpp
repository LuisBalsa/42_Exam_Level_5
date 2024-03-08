#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell*> spells;

		Warlock();
		Warlock(Warlock const &other);
		Warlock &operator=(Warlock const &other);

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);

		void introduce() const;
		void learnSpell(ASpell const *spell);
		void forgetSpell(std::string spell);
		void launchSpell(std::string spell, ATarget const &target);
};
