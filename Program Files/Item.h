#ifndef _Item_included_
#define _Item_included_

#include "Entity.h"

class Item :
	public Entity
{
public:
	Item(void);
	virtual ~Item(void);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual int getWeight();
	virtual void setWeight(int iWeight);
	virtual int getValue();
	virtual void setValue(int iValue);
	virtual int getRarity();
	virtual void setRarity(int iRarity);
	virtual int getEnchantment();
	virtual void setEnchantment(int iEnchantment);
	virtual int getQuantity();
	virtual void setQuantity(int iQuantity);

	virtual void pickUp();

private:
	int m_iWeight;
	int m_iValue;
	int m_iRarity;
	int m_iEnchantment;
	int m_iQuantity;

};

#endif