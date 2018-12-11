/*
	Title: Creature.cpp
	Author: Bryan and Scout
	Date: 10/22/18
	Purpose: This is the file that will creates functions for the Creature class also creates functions of printing.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Creature.h"

using namespace std;
Creature::Creature()
{
	
}
	//destructor
Creature::~Creature()
{
	
}
	
	//accessor
string Creature::getName()
{
	return name;
}
string Creature::getDescription()
{
	return desc;
}
bool Creature::getDangerous()
{
	return isDangerous;
}
float Creature::getCost()
{
	return cost;
}

	//mutator
void Creature::setName(string n)
{
	name = n;
}
void Creature::setDescription(string d)
{
	desc = d;
}
void Creature::setDangerous(bool i)
{
	isDangerous = i;
}
	
void Creature::setCost(float c)
{
	cost = c;
}
	
//other
void Creature::printCreature()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << desc << endl;
	cout << "Is Dangerous: " << isDangerous << endl;
	cout << "Cost: " << cost << endl;
}

void Creature::printCreatureToFile(string filename)
{
	ofstream outFile;
	outFile.open(filename.c_str(), ios_base::app);
	outFile << getName() << endl;
	outFile << getDescription() << endl;
	outFile << getDangerous() << endl;
	outFile << getCost() << endl;


}
