#include "Ammunition.h"

#include <cstdlib>

using namespace std;

Ammunition::Ammunition(void)
{
}


Ammunition::~Ammunition(void)
{
}

void Ammunition::dumpObject()
{
	cout << "Ammunition:" << endl;
	dumpObjectData();
}

void Ammunition::dumpObjectData()
{
	Item::dumpObjectData();

	cout << "   [DamageBonus] " << getDamageBonus() << endl;
	cout << "          [Type] " << getType() << endl;
}

void Ammunition::writeFragment(ostream & output)
{
	output << "   <Ammunition>" << endl;
	writeDataAsFragment(output);
	output << "   </Ammunition>" << endl;
}

void Ammunition::writeDataAsFragment(ostream & output)
{
	Item::writeDataAsFragment(output);

	output << "      <damageBonus>" << getDamageBonus() << "</damageBonus>" << endl;
	output << "      <type>" << getType() << "</type>" << endl;

}

void Ammunition::setElementData(string sElementName, string sValue)
{
	Item::setElementData(sElementName, sValue);

	if( sElementName == "damageBonus" )
	{
		setDamageBonus(atoi(sValue.c_str()));
	}
	else if( sElementName == "type" )
	{
		setType(sValue);
	}

}


int Ammunition::getDamageBonus()
{
	return m_iDamageBonus;
}

void Ammunition::setDamageBonus(int iDamageBonus)
{
	m_iDamageBonus = iDamageBonus;
}

string Ammunition::getType()
{
	return m_sType;
}

void Ammunition::setType(string sType)
{
	m_sType = sType;
}

