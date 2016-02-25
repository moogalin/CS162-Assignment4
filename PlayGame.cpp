
#include "Barbarian.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "LoserStack.hpp"
#include "PlayerQueue.hpp"

int userPromptPlayers();
void createTeams(Creature**, int, Queue*, string );
char playerMenu();

int main() {

	srand((unsigned)time(NULL));

	Stack losers;
	Queue playerQteam1;
	Queue playerQteam2;

	Queue * ptrTeam1 = &playerQteam1;
	Queue * ptrTeam2 = &playerQteam2;
	Stack * ptrLosers = &losers;
	
	Creature ** team1;
	Creature ** team2;

	
	int playersPerTeam = userPromptPlayers();

	team1 = new Creature*[playersPerTeam];
	team2 = new Creature*[playersPerTeam];

	createTeams(team1, playersPerTeam, ptrTeam1, "Team 1");
	createTeams(team2, playersPerTeam, ptrTeam2, "Team 2");

	cout << "Team 1: "<< endl;
	ptrTeam1->display();

	cout << endl << endl;
	cout << "Team 2: " << endl;
	ptrTeam2->display();


	delete team1;
	team1 = NULL;
	delete team2;
	team2 = NULL;

	return 0;
}

int userPromptPlayers() {

	int playersPerTeam;
	cout << "How many players would you like to begin with on each team?" << endl;
	cin >> playersPerTeam;
	cin.ignore();


	while (playersPerTeam < 1 ) {
		cout << "Each team should have at least one player." << endl;
		cin >> playersPerTeam;
		cin.ignore();
	}

	return playersPerTeam;

}


void createTeams(Creature ** player,int numPlayers, Queue * ptrToTeam, string s1) {

	string playerName;
	char identity;
	cout << "Let's choose the players for " << s1 << endl;

	for (int i = 0; i < numPlayers; i++) {
		cout << "What would you like to name Player " << i + 1 << "?" << endl;
		getline(cin, playerName);
		identity = playerMenu();

		switch (identity) {

		case '1':
			player[i] = new Medusa(playerName);
			(*ptrToTeam).add(player[i]);
			break;

		case '2':
			player[i] = new Barbarian(playerName);
			(*ptrToTeam).add(player[i]);
			break;

		case '3':
			player[i] = new Vampire(playerName);
			(*ptrToTeam).add(player[i]);
			break;

		case '4':
			player[i] = new BlueMen(playerName);
			(*ptrToTeam).add(player[i]);
			break;

		case '5':
			player[i] = new HarryPotter(playerName);
			(*ptrToTeam).add(player[i]);
			break;
		}
		
	}




}
	

char playerMenu() {

	char choice;
	bool flag = true;

	cout << "\n Choose Player Identity:" << endl;
	cout << "1. Medusa" << endl;
	cout << "2. Barbarian" << endl;
	cout << "3. Vampire" << endl;
	cout << "4. Blue Men" << endl;
	cout << "5. Harry Potter" << endl;

	cin >> choice;
	cin.ignore();


	while ((choice < '1') || (choice > '5')) {

		cout << "Please enter the integer 1 through 5, only." << endl;
		cout << "Choice: " << endl;
		cin >> choice;
		cin.ignore();
	}

	return choice;
}
