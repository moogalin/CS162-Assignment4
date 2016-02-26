
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

	cout << endl << endl;
	cout << "This is Team 2: " << endl;
	(g1->getTeam1())->display();

	bool flag1 = false;
	bool flag2 = false;

	while ((flag1 == false) && (flag2 == false)) {

		g1->playGame(g1->getTeam1(), g1->getTeam2(), g1->getLosers());

		flag1 = (g1->getTeam1())->isEmpty();
		flag2 = (g1->getTeam2())->isEmpty();

	}

	g1->finalResults(g1->getTeam1(), g1->getTeam2(), g1->getLosers());


	cout << "return 0" << endl;
	delete g1;
	g1 = NULL;
}