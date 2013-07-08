// parser.cpp

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

	while( true )
	{
		// Read a character off the stream
		c = input.get();

		if( c == '<' )
		{

			// Check for the first character
			// being a / -- which indicated an end tag
			if( input.peek() == '/' )
			{
			
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

				//  the end tag's name must match the element's name...
				if( sEndTag != sElementName )
				{
					cout << "Tag name mismatch" << endl;
					return false;
				}

				if( pObject != NULL )
				{
					pObject->setElementData(sElementName, sContent);
				}

				
				return true;

			}
			else
			{
				// In this branch, we have already read in a <,
				// but it was NOT an end tag -- the input file
				// is currently positioned on the first character
				// after the opening <, so we can call parseElement
				// on it
				
				if( !parseElement(input, vWorld, pObject) )
					return false;
			}
		}
		else
		{
			if( c != '\n' )
				sContent.push_back(c);
		}
	}


	return true;
}

// parseXML -- parses an XML document.  

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
	// not a ?, not a valid XML header
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

	// Then check for a > -- which tests for
	// the header ending with ?>
	if( input.get() != '>' )
	{
		cout << "Invalid XML header" << endl;
		return false;
	}

	// Now burn off characters until the first
	// tag after the XML header...
	do
	{
		c = input.get();
	} while( c != '<' );


	// Now on the first character after
	// the opening < -- call parseElement 
	
	return parseElement(input, vWorld, NULL);
}
