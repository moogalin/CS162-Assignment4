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
#include "HarryPotter.hpp"

HarryPotter::HarryPotter(string charName, string teamName) {
	armor = 0;
	strength = 10;
	lifeValue = 2;
	damageTaken = 0;
	attackVal = 0;
	defenseVal = 0;
	name = charName;
	identity = "The Harry Potter";
	team = teamName;
	numDiceAttack = 2;
	numDiceAttackSides = 6;
	numDiceDefense = 2;
	numDiceDefenseSides = 6;
}

HarryPotter::~HarryPotter() {

}


int HarryPotter::attack() {

	attackVal = rollDice(numDiceAttack, numDiceAttackSides);

	return attackVal;


}

/******************************************************************************************
** Function: Defense (Harry Potter special ability: Magical Death Recovery)
** Description: Harry Potter has a special magical ability of recovering from death one time. 
**		When Harry Potter dies once, he returns to life with 20 strength. A subsequent death
**		is permanent. 
** Parameters: N/A
** Pre-Conditions: This function returns specific attack value.
** Post-Conditons: Strength is changed, depending on the damage
******************************************************************************************/
void HarryPotter::defense(int attack) {

	defenseVal = rollDice(numDiceDefense, numDiceDefenseSides);

	int damageTaken = (attack - armor) - defenseVal;

	if (damageTaken > 0) {
		strength -= damageTaken;

	}

	if (strength <= 0 && lifeValue == 2) {
		strength = 20;
		lifeValue = 1;
		cout << " " << name << " " << identity << " dies but magically recovers!" << endl;
	}

	else if (strength <= 0) {
		cout << " " << name << " " << identity << " is unable to recover, and he dies." << endl;
		lifeValue = 0;
	}

}

