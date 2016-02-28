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
#include "Creature.hpp"
#include "Vampire.hpp"

Vampire::Vampire(string charName, string teamName) {
	armor = 1;
	strength = 18;
	damageTaken = 0;
	attackVal = 0;
	defenseVal = 0;
	lifeValue = 1;
	name = charName;
	identity = "The Vampire";
	team = teamName;
	numDiceAttack = 1;
	numDiceAttackSides = 12;
	numDiceDefense = 1;
	numDiceDefenseSides = 6;
}

Vampire::~Vampire() {

}

int Vampire::attack() {

	attackVal = rollDice(numDiceAttack, numDiceAttackSides);

	return attackVal;
	

}

/******************************************************************************************
** Function: Defense (Vampire special ability: Charm)
** Description: The vampire's special ability charm is triggered by an extra dice roll of 
**		1 or 2. If the random number generator returns '2' then the vampire has charmed his
**		opponent into not attacking. Else, the vampire is attacked as normal. 
** Parameters: N/A
** Pre-Conditions: This function receives a specific attack value. 
** Post-Conditons: Strength is changed, depending on the damage 
******************************************************************************************/
void Vampire::defense(int attack) {

	int charm = rollDice(1, 2); // Generate random number 1 or 2. 
	defenseVal = 1000;
	if (charm == 2) {
		cout << " " << name << " " << identity;
		cout << " has charmed his opponent into not attacking him this round." << endl;
		return;
	}

	defenseVal = rollDice(numDiceDefense, numDiceDefenseSides);

	int damageTaken = (attack - armor) - defenseVal;
	if (damageTaken > 0 && charm == 1) {
		strength -= damageTaken;
	}

	
	if (strength <= 0) {
		cout << " " << name << " " << identity << " has died." << endl;
		lifeValue = 0;
	}

}
