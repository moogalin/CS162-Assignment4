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

#include "Barbarian.hpp"


Barbarian::Barbarian(string charName, string teamName) {
	armor = 0;
	strength = 12;
	lifeValue = 1;
	name = charName;
	identity = "The Barbarian";
	team = teamName;
	numDiceAttack = 2;
	numDiceAttackSides = 6;
	numDiceDefense = 2;
	numDiceDefenseSides = 6;
}

Barbarian::~Barbarian() {

}

int Barbarian::attack() {
	int attack = 0;

		attack = rollDice(numDiceAttack, numDiceAttackSides);

		return attack;

}


void Barbarian::defense(int attack) {

	int defense = 0;

	defense = rollDice(numDiceDefense, numDiceDefenseSides);

	cout << "\n Defense: " << defense << endl;

	int damage = (attack - armor) - defense;

	if (damage > 0) {
		strength -= damage;
		cout <<  name << " " << identity << " loses " << damage << " hitpoints. " << endl;
	}

	if (strength <= 0) {
		cout << "The Defending Barbarian has died." << endl;
		lifeValue = 0;
	}

}

