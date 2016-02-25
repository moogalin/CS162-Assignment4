
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
void playGame(Queue* team1, Queue* team2, Stack* loserstack);

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

	cout << "This is Team 1: "<< endl;
	ptrTeam1->display();

	cout << endl << endl;
	cout << "This is Team 2: " << endl;
	ptrTeam2->display();

	bool flag1 = false;
	bool flag2 = false;

	while ( (flag1 == false) && (flag2 == false) ) {

		playGame(ptrTeam1, ptrTeam2, ptrLosers);

		flag1 = ptrTeam1->isEmpty();
		flag2 = ptrTeam2->isEmpty();
	}


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


void playGame(Queue* team1, Queue* team2, Stack* loserstack) {

	Creature * firstplayer = team1->remove();
	Creature * secondplayer = team2->remove();

	int round = 0;


	while ((firstplayer->getStrength() > 0) && (secondplayer->getStrength() > 0)) {
		round++;

		cout << endl << "Start of round " << round << endl;
		cout << firstplayer->getName() << " " << firstplayer->getIdentity() << "attacks!" << endl;
		
		int attack = firstplayer->attack();
		cout << "\n Attack: " << attack << endl;

		cout << " Defending " << secondplayer->getName() << " " << secondplayer->getIdentity();
		cout << " strength: " << secondplayer->getStrength() << endl;
		cout << " " << secondplayer->getName() << " defends with " << secondplayer->getArmor() << " armor!";

		secondplayer->defense(attack);
		cout << " Defending " << secondplayer->getName() << " strength after attack: ";
		cout << secondplayer->getStrength() << endl;

		if (secondplayer->getStrength() > 0) {
		//if (secondplayer->isDead() == false) {
			cout << endl << secondplayer->getName() << " attacks!";
			int attack2 = secondplayer->attack();

			cout << "\n Attack: " << attack2 << endl;

			cout << " Defending " << firstplayer->getName() << " strength: " << firstplayer->getStrength() << endl;
			cout << " " << firstplayer->getName() << " defends with " << firstplayer->getArmor() << " armor!";

			firstplayer->defense(attack2);

			cout << " Defending " << firstplayer->getName() << " strength after attack: " << firstplayer->getStrength() << endl;

		}
	}

	if (firstplayer->getStrength() < 0) {
	//if (firstplayer->isDead() == true) {
		cout << firstplayer->getName() << " " << firstplayer->getIdentity() << " is the loser" << endl;
		loserstack->add(firstplayer);
		team2->add(secondplayer);

	}

	if (secondplayer->getStrength() < 0) {
	//else if (secondplayer->isDead() == true) {
		cout << secondplayer->getName() << " " << secondplayer->getIdentity() << " is the loser" << endl;
		loserstack->add(secondplayer);
		team2->add(firstplayer);
	}

}