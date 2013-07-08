#ifndef _Entity_included_
#define _Entity_included_

#include "XMLSerializable.h"

#include <vector>

class Entity :
	public XMLSerializable
{
public:
	Entity(void);
	virtual ~Entity(void);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual std::string getName();
	virtual void setName(std::string sName);
	virtual char getDisplayChar();
	virtual void setDisplayChar(char cDisplayChar);
	virtual bool hasProperty(std::string sProperty);
	virtual void addProperty(std::string sProperty);
	virtual std::string getDescription();

private:
	std::string m_sName;
	std::vector<std::string> m_vProperties;
	char m_cDisplayChar;
};

#endif