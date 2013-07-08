#include "Gold.h"

using namespace std;

Gold::Gold(void)
{
}


Gold::~Gold(void)
{
}


void Gold::dumpObject()
{
	cout << "Gold:" << endl;
	dumpObjectData();
}

void Gold::writeFragment(ostream & output)
{
	output << "   <Gold>" << endl;
	writeDataAsFragment(output);
	output << "   </Gold>" << endl;
}


void Gold::pickUp()
{
}