#include "Armor.h"

#include <cstdlib>

using namespace std;

Armor::Armor(void)
{
	m_iArmorValue = 0;
}


Armor::~Armor(void)
{
}

void Armor::dumpObject()
{
	cout << "Armor:" << endl;
	dumpObjectData();
}

void Armor::dumpObjectData()
{
	Item::dumpObjectData();

	cout << "          [Type] " << getType() << endl;
	cout << "          [Slot] " << getSlot() << endl;
	cout << "    [ArmorValue] " << getArmorValue() << endl;

}

void Armor::writeFragment(ostream & output)
{
	output << "   <Armor>" << endl;
	writeDataAsFragment(output);
	output << "   </Armor>" << endl;
}

void Armor::writeDataAsFragment(ostream & output)
{
	Item::writeDataAsFragment(output);

	output << "      <type>" << getType() << "</type>" << endl;
	output << "      <slot>" << getSlot() << "</slot>" << endl;
	output << "      <armorValue>" << getArmorValue() << "</armorValue>" << endl;

}

void Armor::setElementData(string sElementName, string sValue)
{
	Item::setElementData(sElementName, sValue);

	if( sElementName == "type" )
	{
		setType(sValue);
	}
	else if( sElementName == "slot" )
	{
		setSlot(sValue);
	}
	else if( sElementName == "armorValue" )
	{
		setArmorValue(atoi(sValue.c_str()));
	}

}




string Armor::getSlot()
{
	return m_sSlot;
}

void Armor::setSlot(std::string sSlot)
{
	m_sSlot = sSlot;
}

string Armor::getType()
{
	return m_sType;
}

void Armor::setType(std::string sType)
{
	m_sType = sType;
}

int Armor::getArmorValue()
{
	return m_iArmorValue;
}

void Armor::setArmorValue(int iArmorValue)
{
	m_iArmorValue = iArmorValue;
}




