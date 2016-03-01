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
#include "PlayGame.hpp"
#include "Barbarian.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "LoserStack.hpp"
#include "PlayerQueue.hpp"


int main() {
	srand((unsigned)time(NULL));

	/* Create game */
	PlayGame* g1 = new PlayGame;

	/* How many players? */
	g1->userPromptPlayers();

	/* Create Teams */
	g1->createTeams((g1->getTeam1()), "Team 1");
	g1->createTeams((g1->getTeam2()), "Team 2");

	/* Display Teams */
	cout << "This is Team 1: " << endl;
	(g1->getTeam1())->display();

	cout << endl;
	cout << "This is Team 2: " << endl;
	(g1->getTeam2())->display();


	string ch;

	/* Choose Output */
	cout << endl;
	cout << "The battle will commence shortly. " << endl;
	cout << "Please choose 1 or 2 from the following: " << endl;
	cout << " 1. View full round, winners, and results." << endl;
	cout << " 2. View condensed battles, winners and results." << endl;
	cout << "Choice: ";
	getline(cin, ch);

	/* Validate Output */
	while ((ch != "1") && (ch != "2")) {
		cout << "Please choose \"1\" or \"2\" ";
		cout << "Note: Only special powers used in a round are displayed during the condensed battle." << endl;
		cout << "Choice: ";
		getline(cin, ch);
	}


		bool teamOneEmpty = false;
		bool teamTwoEmpty = false;


	/* playGame until one team is defeated */
	while ((teamOneEmpty == false) && (teamTwoEmpty == false)) {

		if (ch == "1") {
			cout << "****************************************" << endl;
			g1->playGameOutput();
		}
		if (ch == "2") {
			cout << "****************************************" << endl;
			g1->playGame();
		}

		teamOneEmpty = (g1->getTeam1())->isEmpty();
		teamTwoEmpty = (g1->getTeam2())->isEmpty();

	}

	/* Display Final Results*/
	g1->finalResults();


	delete g1;
	g1 = NULL;

	return 0;
}