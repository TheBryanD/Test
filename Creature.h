/*
	Title: Creature.h
	Author: Bryan and Scout
	Date: 10/22/18
	Purpose: This is a header file to define the Creature class
*/

#if !defined CREATURE_H
#define CREATURE_H

#include <string>

using namespace std;

class Creature
{

	private:
		string name;
		string desc;
		float cost;
		bool isDangerous;
	public:
	//Default constructor
	Creature();
	
	//overloaded constructor
	Creature(string n, string d, float c, bool i)
	{
		name = n;
		desc = d;
		cost = c;
		isDangerous = i;
	}
	
	//destructor
	~Creature();
	
	//accessor
string getName();
	
string getDescription();
	
bool getDangerous();
	
float getCost();
	
	//mutator
void setName(string);
	
void setDescription(string);
	
void setDangerous(bool);
	
void setCost(float);
	
	//other
void printCreature();
	
void printCreatureToFile(string);
};

#endif
