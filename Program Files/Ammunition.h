#ifndef _Ammunition_included_
#define _Ammunition_included_

#include "Item.h"

class Ammunition :
	public Item
{
public:
	Ammunition(void);
	virtual ~Ammunition(void);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual int getDamageBonus();
	virtual void setDamageBonus(int iDamageBonus);
	virtual std::string getType();
	virtual void setType(std::string sType);


private:
	int m_iDamageBonus;
	std::string m_sType;
};

#endif