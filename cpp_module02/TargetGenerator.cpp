#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::TargetGenerator(TargetGenerator const &other) {*this = other;}
TargetGenerator &TargetGenerator::operator=(TargetGenerator const &other) {*this = other; return(*this);}

TargetGenerator::~TargetGenerator()
{
	for (auto it = targets.begin(); it != targets.end(); it++)
		delete it->second;
	targets.clear();
}
void TargetGenerator::learnTargetType(ATarget const *target)
{
	if (target)
		if (targets.find(target->getType()) == targets.end())
			targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string target)
{
	if (targets.find(target) != targets.end())
	{
		delete targets[target];
		targets.erase(target);
	}
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
	if (targets.find(target) != targets.end())
		return targets[target]->clone();
	return NULL;
}

