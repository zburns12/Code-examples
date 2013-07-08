#ifndef _CreatureFactory_included_
#define _CreatureFactory_included_

#include "Creature.h"

#include <vector>
#include <random>

class CreatureFactory
{
public:
	static CreatureFactory & instance();
	virtual ~CreatureFactory();
	Creature * generateCreature(int iMaxLevel);

private:
	CreatureFactory();
	std::vector<Creature*> m_vCreatures;
	std::mt19937 m_mtRandom;
};

#endif
