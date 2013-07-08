#include "Consumable.h"

#include <cstdlib>

using namespace std;


Consumable::Consumable(void)
{
	m_iHealth = 0;
	m_iNutrition = 0;
}


Consumable::~Consumable(void)
{
}

void Consumable::dumpObject()
{
	cout << "Consumable:" << endl;
	dumpObjectData();
}

void Consumable::dumpObjectData()
{
	Item::dumpObjectData();

	cout << "        [Health] " << getHealth() << endl;
	cout << "     [Nutrition] " << getNutrition() << endl;
}

void Consumable::writeFragment(ostream & output)
{
	output << "   <Consumable>" << endl;
	writeDataAsFragment(output);
	output << "   </Consumable>" << endl;
}

void Consumable::writeDataAsFragment(ostream & output)
{
	Item::writeDataAsFragment(output);

	output << "      <health>" << getHealth() << "</health>" << endl;
	output << "      <nutrition>" << getNutrition() << "</nutrition>" << endl;

}

void Consumable::setElementData(string sElementName, string sValue)
{
	Item::setElementData(sElementName, sValue);
	
	if( sElementName == "health" )
	{
		setHealth(atoi(sValue.c_str()));
	}
	else if( sElementName == "nutrition" )
	{
		setNutrition(atoi(sValue.c_str()));
	}

}




void Consumable::use()
{
}


int Consumable::getHealth()
{
	return m_iHealth;
}

void Consumable::setHealth(int iHealth)
{
	m_iHealth = iHealth;
}

int Consumable::getNutrition()
{
	return m_iNutrition;
}

void Consumable::setNutrition(int iNutrition)
{
	m_iNutrition = iNutrition;
}
