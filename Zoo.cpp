/*
	Title: Zoo.cpp
	Author: Bryan and Scout
	Date: 10/22/18
	Purpose: This is the driver to make a creature list.
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include "Creature.h"
#include "LinkedList.h"

using namespace std;

void enterMagicalCreature(LinkedList<Creature>*);

void enterMagicalCreatureFromFile(LinkedList<Creature>*);

void deleteCreature(LinkedList<Creature>*);

void printCreatures(LinkedList<Creature>*);

void saveCreaturesToFile(LinkedList<Creature>*);

int linerSearch(LinkedList<Creature>*, string);

int main ()
{
	//Variables
	int switchNum =0;
	int switchNum2 =0;
		char repeat;
	string searchName;
	
	//List called Creatures
	LinkedList<Creature> Creatures;
	
	do 
	{
	cout << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Enter Creatures " << endl;
	cout << "2. Delete Creature" << endl;
	cout << "3. Print Creatures" << endl;
	cout << "4. Find Creature" << endl;
	cout << "5. Exit Program" << endl;
	
	cin >> switchNum;
	
	switch (switchNum)
	{
		case 1:
			cout << "Would you like to input creatures manually or from a file?" << endl;
			cout << "1. Manually" << endl;
			cout << "2. From a file" << endl;
			cout << "3. Exit" << endl;
			cin >> switchNum2;
			
			switch (switchNum2)
			{
				case 1: 
					
						do 
						{
							enterMagicalCreature(&Creatures);
							cout << "Would you like to enter another creature? (y/n)" << endl;
							cin.clear();
							cin.ignore();
							cin >> repeat;
							while(repeat != 'y' && repeat != 'n')
							{
								cout << "Please enter 'y' or 'n'" << endl;
								cin >> repeat;
							}
						} while (repeat == 'y');
						break;
				
				case 2: enterMagicalCreatureFromFile(&Creatures);
					break;
				case 3: break;
				default: 
					cout << "error with your input" << endl;
					break;
			};
			break;
		case 2: 
			deleteCreature(&Creatures);
			break;
		case 3: 
			printCreatures(&Creatures);
			break;
			
		case 4:
			do {
				int creaturePosition = -1;
				cout << "What Creature are you searching for?" << endl;
				cin >> searchName;
				cout << endl;
			creaturePosition = linerSearch(&Creatures, searchName);
			if (creaturePosition != -1)
			{
				cout << "Creature " << Creatures.getNodeValue(creaturePosition).getName() << " found at position: " << creaturePosition+1 << endl;
				cout << "Name: " << Creatures.getNodeValue(creaturePosition).getName() << endl;
				cout << "Description: " << Creatures.getNodeValue(creaturePosition).getDescription() << endl;
				cout << "Are they dangerous: " << Creatures.getNodeValue(creaturePosition).getDangerous() << endl;
				cout << "Cost: " << Creatures.getNodeValue(creaturePosition).getCost() << endl;
				
			}
			else 
			{
				cout << "Creature not found..." << endl;
			}
			cout << "Would you like to search for another one (y/n)?" << endl;
			cin >> repeat;
			cout << endl;
			} while (repeat == 'y' || repeat == 'Y');
			
			break;
			
		case 5:
			char answer;
			cout << "Would you like to save your creature list to a file? (y/n)" << endl;
			cin >> answer;
			while (answer != 'y' && answer != 'n')
			{
				cout << "Yes or No?" << endl;
				cin >> answer;
			}
			if (answer == 'y')
			{
				saveCreaturesToFile(&Creatures);
			}
			else
			{
			cout << "GOODBYE!" << endl;
			}
			return 0;
		
		default: 
			cout << "error with input" << endl;
			break;
	};
	} while (switchNum != 4);
}

void enterMagicalCreature(LinkedList<Creature> *Creatures)
{
	
	//vars
	string name;
	string description;
	float cost;
	bool isDangerous;
	string boolConv;
	
	cout << "Enter the magical creature's name: " << endl;
	cin.ignore();
	getline(cin, name);
	cout << endl << "Enter the magical creature's description: " << endl;
	getline (cin, description);
	cout << endl << "Is the magical creature dangerous? (y/n): " << endl;
	do{
		cin >> boolConv;
		if (boolConv == "y")
			isDangerous = true;
		else if (boolConv == "n")
			isDangerous = false;
		else
			cout << "did not enter valid answer please use 'y' or 'n'" << endl;
	} while (boolConv != "y" && boolConv != "n");
	cout << endl << "Enter the magical creature's cost (per month): " << endl << "$";
	cin >> cost;
	
	Creature newCreature(name, description, cost, isDangerous);
	
	cout << endl << name << " added to the list." << endl << endl;
	Creatures->appendNode(newCreature);
	
	
	cout << "length: " << Creatures->getLength()<<endl;
	
}

void enterMagicalCreatureFromFile(LinkedList<Creature> *Creatures)
{
	ifstream inFile;
	ofstream outFile;
	string filename;
	string name;
	string desc;
	bool isDangerous;
	float cost;
	int counter =0;
	
	cout << "What file would you like to input from?" << endl;
	cin >> filename;
	
	
	inFile.open (filename.c_str());

	while (!inFile)
	{
		cout << "Invalid file, try again: " << endl;
		cin >> filename;
		inFile.open(filename.c_str());
	}
	
	cout << endl;
	while (!inFile.eof())
	{
		//inFile.clear();
		//inFile.ignore();
		getline(inFile, name);
		//inFile.clear();
		//inFile.ignore();
		getline(inFile, desc);
		//inFile.clear();
		//inFile.ignore();
		inFile >> isDangerous;
		inFile >> cost;
		
		Creature newCreature(name, desc, cost, isDangerous);
		Creatures->appendNode(newCreature);
		
		cout << newCreature.getName() << " was added to your library!" << endl;
		cout << newCreature.getDescription() << endl;
		cout << newCreature.getCost() << endl;
		cout << newCreature.getDangerous() << endl;
		//cout << Creatures->getLength();

		counter++;
		inFile.clear();
		inFile.ignore();
	}
	
	inFile.close();
		
	cout << "The number of creatures added were: " << counter << endl;
	
}

void deleteCreature(LinkedList<Creature> *Creatures)
{

	int length = Creatures->getLength();
	int index =0;
	if (length == 0)
	{
		cout << "There are no creatures in the zoo to delete." << endl;
	}
	else
	{
		cout << endl;
		for (int i =0; i < length; i++)
		{
			Creature newCreature = Creatures->getNodeValue(i);
			cout << i+1 << ".) " << newCreature.getName() << endl;
		}
		cout << endl << "Which creature would you like to delete? " << endl;
		cin >> index;
		Creatures->deleteNode(index-1);
	
	}
	
	 cout << "Successfully removed the creature..." << endl;
}

void printCreatures(LinkedList<Creature> *Creatures)
{
	int length = Creatures->getLength();
	cout << endl;
	if (length != 0)
	{
		for (int i =0; i < length; i++)
		{
			Creature newCreature = Creatures->getNodeValue(i);
			newCreature.printCreature();
			cout << endl;
		}
	}
	else
	{
		cout << "There are no creatures in your zoo." << endl;
	}
}

void saveCreaturesToFile(LinkedList<Creature> *Creatures)
{
	string filename;
	if (Creatures->getLength() == 0)
	{
		cout << "THERE ARE NO CREATURES AT YOUR ZOO!" << endl;
	}
	else 
	{
		cout << "What file would you like to save your zoo to?" << endl;
		cin >> filename;
		int length = Creatures->getLength();
		for (int i =0; i < length; i++)
		{
			Creature v = Creatures->getNodeValue(i);
				ifstream inFile;
				ofstream outFile;
				v.printCreatureToFile(filename);
			
		}
	}
}

int linerSearch(LinkedList<Creature>* Creatures, string CreatureName)
{
	int position = -1;
	bool found = false;
	
	for (int i =0; i < Creatures->getLength() && !found; i++)
	{
		if (CreatureName == Creatures->getNodeValue(i).getName())
		{
			position = i;
			found = true;
		}
	}
	return position;
}