#include "Item.h"

#include <cstdlib>

using namespace std;

Item::Item(void)
{
	m_iEnchantment = 0;
	m_iQuantity = 1;
	m_iValue = 0;
	m_iRarity = 0;
}


Item::~Item(void)
{
}

void Item::dumpObject()
{
	cout << "Item:" << endl;
	dumpObjectData();
}

void Item::dumpObjectData()
{
	Entity::dumpObjectData();

	cout << "        [Weight] " << getWeight() << endl;
	cout << "         [Value] " << getValue() << endl;
	cout << "      [Quantity] " << getQuantity() << endl;
	cout << "   [Enchantment] " << getEnchantment() << endl;

}

void Item::writeFragment(ostream & output)
{
	output << "   <Item>" << endl;
	writeDataAsFragment(output);
	output << "   </Item>" << endl;
}

void Item::writeDataAsFragment(ostream & output)
{
	Entity::writeDataAsFragment(output);

	output << "      <weight>" << getWeight() << "</weight>" << endl;
	output << "      <value>" << getValue() << "</value>" << endl;
	output << "      <quantity>" << getQuantity() << "</quantity>" << endl;
	output << "      <enchantment>" << getEnchantment() << "</enchantment>" << endl;

}

void Item::setElementData(string sElementName, string sValue)
{
	Entity::setElementData(sElementName, sValue);

	if( sElementName == "weight" )
	{
		setWeight(atoi(sValue.c_str()));
	}
	else if( sElementName == "value" )
	{
		setValue(atoi(sValue.c_str()));
	}
	else if( sElementName == "quantity" )
	{
		setQuantity(atoi(sValue.c_str()));
	}
	else if( sElementName == "enchantment" )
	{
		setEnchantment(atoi(sValue.c_str()));
	}
}




int Item::getWeight() 
{ 
	return m_iWeight;
}

void Item::setWeight(int iWeight)
{ 
	m_iWeight = iWeight;
}

int Item::getValue()
{
	return m_iValue;
}

void Item::setValue(int iValue) 
{ 
	m_iValue = iValue;
}


int Item::getRarity() 
{ 
	return m_iRarity;
}

void Item::setRarity(int iRarity) 
{ 
	m_iRarity = iRarity;
}

int Item::getEnchantment() 
{ 
	return m_iEnchantment;
}

void Item::setEnchantment(int iEnchantment) 
{
	m_iEnchantment = iEnchantment;
}

int Item::getQuantity() 
{ 
	return m_iQuantity;
}

void Item::setQuantity(int iQuantity) 
{ 
	m_iQuantity = iQuantity;
}

void Item::pickUp()
{
}
