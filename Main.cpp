
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

	PlayGame* g1 = new PlayGame;

	g1->userPromptPlayers();

	g1->createTeams((g1->getTeam1()), "Team 1");
	g1->createTeams((g1->getTeam2()), "Team 2");


	cout << "This is Team 1: " << endl;
	(g1->getTeam1())->display();

	cout << endl;
	cout << "This is Team 2: " << endl;
	(g1->getTeam1())->display();


	string ch;

	cout << endl;
	cout << "The battle will commence shortly. " << endl;
	cout << "Please choose 1 or 2 from the following: " << endl;
	cout << " 1. View full round, winners, and results." << endl;
	cout << " 2. View condensed battles, winners and results." << endl;
	cout << "Choice: ";
	getline(cin, ch);

	while ((ch != "1") && (ch != "2")) {
		cout << "Please choose \"1\" or \"2\" ";
		cout << "Note: Only special powers used in a round are displayed during the condensed battle." << endl;
		cout << "Choice: ";
		getline(cin, ch);
	}


		bool teamOneEmpty = false;
		bool teamTwoEmpty = false;


	//playGame until one team is defeated
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

	g1->finalResults();


	delete g1;
	g1 = NULL;

	return 0;
}