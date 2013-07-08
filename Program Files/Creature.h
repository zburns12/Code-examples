#ifndef _Creature_included_
#define _Creature_included_

#include "Entity.h"

class Creature :
	public Entity
{
public:
	Creature(void);
	virtual ~Creature(void);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual int getLevel();
	virtual void setLevel(int iLevel);
	virtual int getHP();
	virtual void setHP(int iHP);
	virtual int getMaxHP();
	virtual void setMaxHP(int iMaxHP);

private:
	int m_iLevel;
	int m_iHP;
	int m_iMaxHP;

	// Not worried about inventory yet...
	//std::vector<Item*> m_vInventory;

};

#endif

