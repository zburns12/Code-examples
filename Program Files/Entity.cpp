#include "Entity.h"

using namespace std;

Entity::Entity(void)
{
	m_cDisplayChar = '?';
}


Entity::~Entity(void)
{
}


void Entity::dumpObject()
{
	cout << "Entity:" << endl;
	dumpObjectData();
}

void Entity::dumpObjectData()
{
	XMLSerializable::dumpObjectData();

	cout << "          [Name] " << getName() << endl;
	cout << "   [DisplayChar] " << getDisplayChar() << endl;
	cout << "    [Properties] " << endl;

	for( auto it = m_vProperties.begin();
		it != m_vProperties.end();
		it++ )
	{
		cout << "       - " << (*it) << endl;
	}
}

void Entity::writeFragment(ostream & output)
{
	output << "   <Entity>" << endl;
	writeDataAsFragment(output);
	output << "   </Entity>" << endl;
}

void Entity::writeDataAsFragment(ostream & output)
{
	XMLSerializable::writeDataAsFragment(output);

	output << "      <name>" << getName() << "</name>" << endl;
	output << "      <displayChar>" << getDisplayChar() << "</displayChar>" << endl;
	output << "      <properties>" << endl;

	for( auto it = m_vProperties.begin();
		it != m_vProperties.end();
		it++ )
	{
		output << "         <property>" << (*it) << "</property>" << endl;
	}

	output << "      </properties>" << endl;
}

void Entity::setElementData(string sElementName, string sValue)
{
	XMLSerializable::setElementData(sElementName, sValue);

	if( sElementName == "property" )
	{
		addProperty(sValue);
	}
	else if( sElementName == "name" )
	{
		setName(sValue);
	}
	else if( sElementName == "displayChar" )
	{
		if( sValue.length() > 0 )
			setDisplayChar(sValue[0]);
	}
}

string Entity::getDescription()
{
	// placeholder
	return getName();
}

string Entity::getName()
{
	return m_sName;
}

void Entity::setName(string sName)
{
		m_sName = sName;
}

bool Entity::hasProperty(string sProperty)
{
	for( auto it = m_vProperties.begin();
		it != m_vProperties.end();
		it++ )
	{
		if( (*it) == sProperty )
			return true;
	}

	return false;
}

void Entity::addProperty(string sProperty)
{
	m_vProperties.push_back(sProperty);
}

char Entity::getDisplayChar()
{
	return m_cDisplayChar;
}

void Entity::setDisplayChar(char cDisplayChar)
{
	m_cDisplayChar = cDisplayChar;
}

