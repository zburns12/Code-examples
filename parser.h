#ifndef _parser_included_
#define _parser_included_

#include <iostream>
#include <vector>

#include "XMLSerializable.h"

void parseXML(std::istream & input, std::vector<XMLSerializable*> & vWorld);

#endif
