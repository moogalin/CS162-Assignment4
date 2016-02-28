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
	damageTaken = 0;
	attackVal = 0;
	defenseVal = 0;
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
	attackVal = rollDice(numDiceAttack, numDiceAttackSides);

	return attackVal;


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

	defenseVal = rollDice(numDiceDefense, numDiceDefenseSides);

	damageTaken = (attack - armor) - defenseVal;

	if (damageTaken > 0 ) {
		strength -= damageTaken;
	}
	if (strength <= 8 && mob == 2) {
		numDiceDefense--;
		cout << " Oh no! A member of the BlueMen mob dies. Their defense is now reduced." << endl;
		--mob;

		
	}
	if (strength <= 4 && mob == 1) {
		numDiceDefense--;
		cout << " Oh no! Another member of the BlueMen mob dies. Their defense is now reduced." << endl;
		--mob;
	}

	if (strength <= 0) {
		cout << " " << name << " " << identity << " has died." << endl;
		lifeValue = 0;
	}

}

