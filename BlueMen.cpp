/******************************************************************************************
** Program Filename: Assignment 4
** Author: Megan Aldridge
** Date: February 28, 2016
** Description: This program allows a user to create two teams of Creatures that will
**		battle in pairs until death!
** Input: User will select the number of players in each team and then the user will select
**		from a menu to determine which Creatures will fight and name each creature.
** Output: The output displays each round of the fight including each creatures armor,
**		die roll, strength (before and after defending), and the result of the battle.
**		At the end of all paired battles, the output will display the players remaining
**		in the winning team and the losers (incapacitated players) as well as the 1st,
**		2nd, and 3rd place victors.
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

