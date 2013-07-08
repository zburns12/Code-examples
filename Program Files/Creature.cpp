#include "Creature.h"

#include <cstdlib>

using namespace std;

Creature::Creature(void)
{
	m_iHP = 0;
	m_iMaxHP = 0;
	m_iLevel = 0;
}


Creature::~Creature(void)
{
}


void Creature::dumpObject()
{
	cout << "Creature:" << endl;
	dumpObjectData();
}

void Creature::dumpObjectData()
{
	Entity::dumpObjectData();

	cout << "         [Level] " << getLevel() << endl;
	cout << "            [HP] " << getHP() << endl;
	cout << "         [MaxHP] " << getMaxHP() << endl;
}

void Creature::writeFragment(ostream & output)
{
	output << "   <Creature>" << endl;
	writeDataAsFragment(output);
	output << "   </Creature>" << endl;
}

void Creature::writeDataAsFragment(ostream & output)
{
	Entity::writeDataAsFragment(output);

	output << "      <level>" << getLevel() << "</level>" << endl;
	output << "      <HP>" << getHP() << "</HP>" << endl;
	output << "      <maxHP>" << getMaxHP() << "</maxHP>" << endl;

}

void Creature::setElementData(string sElementName, string sValue)
{
	Entity::setElementData(sElementName, sValue);

	if( sElementName == "level" )
	{
		setLevel(atoi(sValue.c_str()));
	}
	else if( sElementName == "maxHP" )
	{
		setMaxHP(atoi(sValue.c_str()));
	}
	else if( sElementName == "HP" )
	{
		setHP(atoi(sValue.c_str()));
	}

}


int Creature::getLevel()
{
	return m_iLevel;
}

void Creature::setLevel(int iLevel)
{
	m_iLevel = iLevel;
}

int Creature::getHP()
{
	return m_iHP;
}

void Creature::setHP(int iHP)
{
	m_iHP = iHP;
}

int Creature::getMaxHP()
{
	return m_iMaxHP;
}

void Creature::setMaxHP(int iMaxHP)
{
	m_iMaxHP = iMaxHP;
}