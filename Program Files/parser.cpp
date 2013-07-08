// parser.cpp
//
// Example XML parser -- framework for PA1 part 2 parsing
//
// Feel free to use for your assignment; note that
// you will have to make some modifications to this
// to get it to meet the requirements.
//
// Note that for this code example to work, you will
// need to have a world.xml in the same directory
// you run it from.

#include <iostream>
#include <string>
#include <fstream>

#include "Ammunition.h"
#include "Armor.h"
#include "Consumable.h"
#include "Creature.h"
#include "Entity.h"
#include "Gold.h"
#include "Item.h"
#include "Potion.h"
#include "Scroll.h"
#include "Weapon.h"
#include "XMLSerializable.h"

using namespace std;


bool parseElement(istream & input, vector<XMLSerializable*> & vWorld, XMLSerializable * pObject)
{	
	// char to hold data as we process it
	char c;

	// The name of the element; initialized to
	// an empty string (as all strings are by default);
	// we get this by reading in the XML
	string sElementName;


	// Read in the XML one character at a time, checking
	// for the > at the end of the tag
	do
	{
		// Get the character off the stream		
		c = input.get();

		// If it's not the end tag, add it to the element name
		if( c != '>' )
			sElementName.push_back(c);

	} while( c != '>' );

	if( sElementName == "Item" )
	{
		pObject = new Item;
		vWorld.push_back(pObject);
	}
	else if( sElementName == "Creature" )
	{
		pObject = new Creature;
		vWorld.push_back(pObject);
	}
	else if( sElementName == "Consumable" )
	{
		pObject = new Consumable;
		vWorld.push_back(pObject);
	}
	else if( sElementName == "Weapon" )
	{
		pObject = new Weapon;
		vWorld.push_back(pObject);
	}
	else if( sElementName == "Armor" )
	{
		pObject = new Armor;
		vWorld.push_back(pObject);
	}
	else if( sElementName == "Gold" )
	{
		pObject = new Gold;
		vWorld.push_back(pObject);
	}
	else if( sElementName == "Ammunition" )
	{
		pObject = new Ammunition;
		vWorld.push_back(pObject);
	}
	else if( sElementName == "Potion" )
	{
		pObject = new Potion;
		vWorld.push_back(pObject);
	}
	else if( sElementName == "Scroll" )
	{
		pObject = new Scroll;
		vWorld.push_back(pObject);
	}


	// Holds the non-element content of the element
	string sContent;

	// while(true) can be dangerous, but we do have paths
	// out of the function.
	while( true )
	{
		// Read a character off the stream
		c = input.get();

		// The important thing is to check to see if
		// it is an open angled bracket.
		if( c == '<' )
		{
			// If it is, we have two possibilities (assuming
			// the XML is valid):
			//
			// Either this is the start tag for a new element
			// contained in the current element, or it's
			// the end tag for our current element.
			//
			// Note that if it is an end tag -- and the XML is
			// valid -- it MUST be the end tag of the current element
			// as elements are not allowed to overlap.

			// So we check for the first character
			// being a / -- which indicated an end tag
			if( input.peek() == '/' )
			{
				// We must burn off the / since
				// we only peeked it, and haven't
				// gotten it yet!
				input.get();

				// Variable to hold the end tag as
				// we read it in
				string sEndTag;

				// Read in the end tag until we get
				// to the > at the end of the tag
				do
				{
					c = input.get();
					if( c != '>' )
						sEndTag.push_back(c);

				} while( c != '>' );

				// Now, we test for the validity of the XML -- the 
				// end tag's name must match the element's name...
				if( sEndTag != sElementName )
				{
					cout << "Tag name mismatch" << endl;
					return false;
				}

				if( pObject != NULL )
				{
					pObject->setElementData(sElementName, sContent);
				}

				// And since we have fully parsed an element, we
				// return to whatever called us in the first place
				return true;

			}
			else
			{
				// In this branch, we have already read in a <,
				// but it was NOT an end tag -- the input file
				// is currently positioned on the first character
				// after the opening <, so we can call parseElement
				// on it...
				//
				// Here we're passing the hierarchy we know plus
				// the current element name, so this next element
				// knows where it is in the overal document 
				// hiearchy
				if( !parseElement(input, vWorld, pObject) )
					return false;
			}
		}
		else
		{
			// In this branch, we have read in a character inside
			// the element which is not a < -- since it's not
			// part of an interior element, it's content, so
			// we add it to our variable which stores the
			// content (ignoring end-of-line characters).
			if( c != '\n' )
				sContent.push_back(c);
		}
	}


	return true;
}

// parseXML -- parses an XML document.  First it
// makes a very half-hearted check for the validity
// of the XML header, then it parses the root
// element of the document.
bool parseXML(istream & input, vector<XMLSerializable*> & vWorld)
{
	char c;

	// Read in the XML, one character at a time,
	// until we hit a <.
	do
	{
		c = input.get();
	} while( c != '<' );

	// Check the character after the < -- if it's
	// not a ?, we aren't seeing a valid XML header
	if( input.get() != '?' )
	{
		cout << "Invalid XML header" << endl;
		return false;
	}

	// Burn off the rest of the header, looking for
	// a ?
	do
	{
		c = input.get();
	} while( c != '?' );

	// Then we check for a > -- which tests for
	// the header ending with ?>
	if( input.get() != '>' )
	{
		cout << "Invalid XML header" << endl;
		return false;
	}

	// Now burn off characters until we get to the first
	// tag after the XML header...
	do
	{
		c = input.get();
	} while( c != '<' );


	// And so, we're now on the first character after
	// the opening < -- which is exactly what parseElement
	// expects.  So we call it.
	return parseElement(input, vWorld, NULL);
}
