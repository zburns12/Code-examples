#ifndef _Armor_included_
#define _Armor_included_

#include "Item.h"

class Armor :
	public Item
{
public:
	Armor(void);
	virtual ~Armor(void);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual std::string getSlot();
	virtual void setSlot(std::string sSlot);
	virtual std::string getType();
	virtual void setType(std::string sType);
	virtual int getArmorValue();
	virtual void setArmorValue(int iArmorValue);

private:
	std::string m_sSlot;
	std::string m_sType;
	int m_iArmorValue;
};


#endif