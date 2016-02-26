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
#include "BlueMen.hpp"

BlueMen::BlueMen(string charName, string teamName) {
	armor = 3;
	strength = 12;
	lifeValue = 1;
	mob = 2;
	name = charName;
	team = teamName;
	identity = "The Blue Men";
	numDiceAttack = 2;
	numDiceAttackSides = 10;
	numDiceDefense = 3;
	numDiceDefenseSides = 6;
}

BlueMen::~BlueMen() {

}


int BlueMen::attack() {
	int attack = 0;

	attack = rollDice(numDiceAttack, numDiceAttackSides);

	return attack;


}

/******************************************************************************************
** Function: Defense (Blue Men Special: Mob)
** Description: The four Blue Men have a special defense capability Mob. For each 4 strength 
**		points lost, the Blue Men lose one defense die. This results in a lower net defense
** Parameters: N/A
** Pre-Conditions: This function a specific attack value.
** Post-Conditons: Strength is changed, depending on the damage
******************************************************************************************/
void BlueMen::defense(int attack) {

	int defense = 0;

	defense = rollDice(numDiceDefense, numDiceDefenseSides);

	int damage = (attack - armor) - defense;

	if (damage > 0 ) {
		strength -= damage;
		cout << name << " " << identity << " loses " << damage << " hitpoints. " << endl;
	}
	cout << "mob" << mob << endl;
	if (strength <= 8 && mob == 2) {
		numDiceDefense--;
		cout << endl << "Oh no! A member of the BlueMen mob dies. Their defense is now reduced." << endl;
		--mob;

		
	}
	if (strength <= 4 && mob == 1) {
		numDiceDefense--;
		cout << "Oh no! Another member of the BlueMen mob dies. Their defense is now reduced." << endl;
		--mob;
	}



	cout << "\n Defense: " << defense << endl;
	if (attack == 0) {
		cout << "Error: Attacking fighter is not alive." << endl;
		return;
	}

	if (strength <= 0) {
		cout << "The Defending BlueMen have all died." << endl;
		lifeValue = 0;
	}

}

