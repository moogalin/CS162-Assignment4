/******************************************************************************************
** Program Filename: Assignment 3
** Author: Megan Aldridge
** Date: February 14, 2016
** Description: This program allows a user to create two Barbarian, Vampire, Blue Men, Medusa
**		or Harry Potter (Creature objects) and subsequently enter those objects into a random
**		die roll based duel where they will lose attack, lose strength, and (if applicable)
**			use special powerups!
** Input: User will select from a menu to determine which Creatures will fight. User
**		will then choose whether to continue a fight, quit the fight, start a new battle,
**		or quit entirely.
** Output: The output displays each round of the fight including each creatures armor,
**		die roll, strength (before and after defending), and the result of the battle.
**		Menu functions also display choices to allow the user to determine if they want
**		to continue the battle, start a new one, or quit.
******************************************************************************************/
#include "Medusa.hpp"
#include "Creature.hpp"

Medusa::Medusa(string charName, string teamName) {
	armor = 3;
	strength = 8;
	lifeValue = 1;
	name = charName;
	identity = "The Medusa";
	team = "teamName";
	numDiceAttack = 2;
	numDiceAttackSides = 6;
	numDiceDefense = 1;
	numDiceDefenseSides = 6;
}

Medusa::~Medusa() {

}

/******************************************************************************************
** Function: Medusa Attack (special powerup)
** Description: This attack function uniquely allows Medusa to perform the Glare superpower
**		as a result of Glare, her enemy is immediately killed with an attack of 1000. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: Glare occurs if the rollDice function returns a value of 12. 
******************************************************************************************/
int Medusa::attack() {
	int attack = 0;
	int glare = 10000;

	attack = rollDice(numDiceAttack, numDiceAttackSides);

	if (attack == 12) {
		cout << endl << "Oh no! The target has looked into her eyes and is turned to stone." << endl;
		return glare;
	}

	else {
		return attack;
	}

}


void Medusa::defense(int attack) {

	int defense = 0;

	defense = rollDice(numDiceDefense, numDiceDefenseSides);

	cout << "\n Defense: " << defense << endl;
	if (attack == 0) {
		cout << "Error: Attacking fighter is not alive." << endl;
		return;
	}

	int damage = (attack - armor) - defense;

	if (damage > 0) {
		strength -= damage;
		cout << name << " " << identity << " loses " << damage << " hitpoints. " << endl;
	}

	if (strength <= 0) {
		cout << "The Defending Medusa has died." << endl;
		lifeValue = 0;
	}

}