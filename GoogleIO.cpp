/*
Travieon Fields
Assignment 2 Assignment: I/O file

A spellbook That I decided to make for this assignment 


*/




#include <iostream>
#include <string>
#include <deque>
#include <fstream>
#include <string>
#include <string.h>
#include<Windows.h>




void SpellChoiceChecker();
void makeASpell();
void AddSpellToBook();
void findSpellFromSpellBook();

using namespace std;
int userChoice;
int spellChoice = 6;
bool spellHasBeenChoosen;

deque<string> spells;
string spell;
string spellName;
string elementChoice;
string fire = "Fire";
string ice = "Ice";
string water = "Water";
string earth = "Earth";







HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int main()
{


	cout << "Ah you Have Open The Book Of All Magic Great Wizard" << endl;
	cout << "What do you wish To Do?" << endl;
	cout << "0)Add A Spell 1)Recall the Spells" << endl;
	cin >> userChoice;

	if (userChoice == 0)
	{
		makeASpell();
	}
	else if (userChoice == 1)
	{
	findSpellFromSpellBook();
	}
	
}


void makeASpell()
{
	cout << "You wish To add A spell Of Your Own Very Well . . . " << endl;
	cout << "What is The name Of your Spell? (Please Write as One Word)" << endl;
	cin >> spellName;
	
	



	if (!spellHasBeenChoosen)
	{
		
		SpellChoiceChecker();
		
		SetConsoleTextAttribute(h, 15);
		cout << "Ah, Yes " << elementChoice << " Great choice!" << endl;

		cout << " Shall be added To the List" << " Thank you!" << endl;

		AddSpellToBook();
	}
	else
	{
		cout << "What is The name Of your Spell?" << endl;
		getline(cin, spellName);
	}

	

}

void SpellChoiceChecker()
{
	SetConsoleTextAttribute(h, 15);
	cout << "What attribute do you wish to Add to your Spell?" << endl;
	SetConsoleTextAttribute(h, 4);
	cout << "0)Fire ";
	SetConsoleTextAttribute(h, 3);
	cout << "1)Ice ";
	SetConsoleTextAttribute(h, 1);
	cout << "2)Water ";
	SetConsoleTextAttribute(h, 6);
	cout << "3)Earth " << endl;

	SetConsoleTextAttribute(h, 15);
	cin >> spellChoice;



	while (!spellHasBeenChoosen)
	{
		

		switch (spellChoice)
		{

		case 0:
		cout << "You have Choosen Fire as The spells Attribute" << endl;
		elementChoice = fire;
		spellHasBeenChoosen = true;
		break;

		case 1:
			cout << "You have Choosen Ice as The spells Attribute" << endl;
			elementChoice = ice;
			spellHasBeenChoosen = true;
			break;

		case 2:
			cout << "You have Choosen Water as The spells Attribute" << endl;
			elementChoice = water;
			spellHasBeenChoosen = true;
			break;

		case 3:
			cout << "You have Choosen Earth as The spells Attribute" << endl;
			elementChoice = earth;
			spellHasBeenChoosen = true;
			break;



		default:
			cout << "A spell Elememt has not been choosen" << endl;
			cin >> spellChoice;
			spellHasBeenChoosen = false;
			break;
		}



	}


}

//Add new spells to my text files 
void AddSpellToBook()
{
	ofstream spellOutput("SaveSpells.txt", std::ios::app);
	
	if (spellOutput.is_open()) 
	{

		cout << spellName << endl;
		spellOutput << elementChoice << ":Element:" << spellName << "\n";
	}
			
	spellOutput.close();
	
}

//Find my text files and Change the colors 
void findSpellFromSpellBook()
{
	ifstream spellInput("SaveSpells.txt");
	

	if (spellInput.is_open()) {
		
		
		while (getline(spellInput,spell))
		{
			
			spellInput >> spell;
			spells.push_back(spell);

			if (spell.compare(0,4,fire) == 0)
			{
				SetConsoleTextAttribute(h, 4);
				
			}
			else if (spell.compare(0, 3, ice) == 0)
			{
				SetConsoleTextAttribute(h, 3);
				
			}
			else if (spell.compare(0, 5, water) == 0)
			{
				SetConsoleTextAttribute(h, 1);
			
			}
			 else if (spell.compare(0, 5, earth) == 0)
			{
				SetConsoleTextAttribute(h, 6);
			}



			cout << spell << endl;
			
			
		}
	
	}
	spellInput.close();
	SetConsoleTextAttribute(h, 15);
	system("pause");
	return;
}




