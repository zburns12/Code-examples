#ifndef _Gold_included_
#define _Gold_included_

#include "Item.h"

class Gold :
	public Item
{
public:
	Gold(void);
	virtual ~Gold(void);

	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);

	virtual void pickUp();
};

#endif

