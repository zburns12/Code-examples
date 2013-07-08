#include "CreatureFactory.h"
#include "XMLSerializable.h"
#include "parser.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;


CreatureFactory & CreatureFactory::instance()
{
	static CreatureFactory Creature;
	return Creature;
}
Creature * CreatureFactory::generateCreature(int iMaxLevel)
{
	vector<Creature*> creatures;

	CreatureFactory &Factory = CreatureFactory::instance();

	for(auto it = m_vCreatures.begin(); it != m_vCreatures.end(); it++)
	{
		if(1  <= iMaxLevel)
		{
			creatures.push_back(*it);
		}
	}

	int iRandom = m_mtRandom();
	int iRandomCreature = iRandom % (creatures.size() - 1);

	Creature * RandomCreature = creatures[iRandomCreature];
	Creature * pReturnValue = new Creature(*RandomCreature);

	return pReturnValue;
}

CreatureFactory::CreatureFactory()
{
	m_mtRandom.seed( time(NULL) );

	ifstream input;
	input.open("critters.xml");
	vector<XMLSerializable*> pObject;
	parseXML(input,pObject);

	for(auto it = pObject.begin(); it != pObject.end(); it++)
	{
		Creature * pCreature = dynamic_cast<Creature*>(*it);
		m_vCreatures.push_back(pCreature);
	}

}

CreatureFactory::~CreatureFactory()
{
}


