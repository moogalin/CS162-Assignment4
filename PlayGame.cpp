#include "PlayGame.hpp"

PlayGame::PlayGame() {
	ptrTeam1 = &playerQteam1;
	ptrTeam2 = &playerQteam2;
	ptrLosers = &losers;
	playerPtr = NULL;

}

PlayGame::~PlayGame() {
	delete playerPtr;
	playerPtr = NULL;

}

PlayGame::PlayGame(const PlayGame &obj) {
	*playerPtr = *obj.playerPtr;

}

Queue* PlayGame::getTeam1() {
	return ptrTeam1;
}

Queue* PlayGame::getTeam2() {
	return ptrTeam2;
}

Stack* PlayGame::getLosers() {

	return ptrLosers;
}

void PlayGame::userPromptPlayers() {

	int players;
	cout << "How many players would you like to begin with on each team?" << endl;
	cin >> players;
	cin.ignore();


	while (players< 1 ) {
		cout << "Each team should have at least one player." << endl;
		cin >> players;
		cin.ignore();
	}

	playersPerTeam = players;

}

void PlayGame::createTeams(Queue* ptrToTeam, string s1) {

	string playerName;
	char identity;
	cout << "Let's choose the players for " << s1 << endl;

	for (int i = 0; i < playersPerTeam; i++) {
		Creature * playerPtr = NULL;
		Creature * temp = NULL; //new
		cout << "What would you like to name Player " << i + 1 << "?" << endl;
		getline(cin, playerName);
		identity = playerMenu();

		if (identity == '1') {
			playerPtr = new Medusa(playerName, s1);
			ptrToTeam->add(playerPtr);
		}

		else if (identity == '2') {
			playerPtr = new Barbarian(playerName, s1);
			ptrToTeam->add(playerPtr);
		}

		else if (identity == '3') {
			playerPtr = new Vampire(playerName, s1);
			ptrToTeam->add(playerPtr);
		}

		else if (identity == '4') {
			playerPtr = new BlueMen(playerName, s1);
			ptrToTeam->add(playerPtr);
		}

		else if (identity == '5') {
			playerPtr = new HarryPotter(playerName, s1);
			ptrToTeam->add(playerPtr);
		}

		else {

		}

		/*switch (identity) {

		case '1':	playerPtr = new Barbarian(playerName, s1);
			ptrToTeam->add(playerPtr);
			playerPtr = new Medusa(playerName, s1);
			ptrToTeam->add(playerPtr);
			break;

		case '2':
			playerPtr = new Barbarian(playerName, s1);
			ptrToTeam->add(playerPtr);
			break;

		case '3':
			playerPtr = new Vampire(playerName, s1);
			ptrToTeam->add(playerPtr);
			break;

		case '4':
			playerPtr = new BlueMen(playerName, s1);
			ptrToTeam->add(playerPtr);
			break;

		case '5':
			playerPtr = new HarryPotter(playerName, s1);
			ptrToTeam->add(playerPtr);
			break;
			
		default:
			cout << "Error" << endl;
		}*/
	
	}





}
	
char PlayGame::playerMenu() {

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

void PlayGame::playGame(Queue* team1, Queue* team2, Stack* loserstack) {
	int dieRoll = (rand() % 2) + 1;
	Creature * firstplayer;
	Creature * secondplayer;

	if (dieRoll == 1) {
		firstplayer = team1->remove();
		secondplayer = team2->remove();
	}

	else {
		firstplayer = team2->remove();
		secondplayer = team1->remove();
	}

	int round = 0;


	while ((firstplayer->getStrength() > 0) && (secondplayer->getStrength() > 0)) {
		round++;

		cout << endl << "Start of round " << round << endl;
		cout << firstplayer->getName() << " " << firstplayer->getIdentity() << "attacks!" << endl;
		
		int attack = firstplayer->attack();
		//cout << "\n Attack: " << attack << endl;

		//cout << " Defending " << secondplayer->getName() << " " << secondplayer->getIdentity();
		//cout << " strength: " << secondplayer->getStrength() << endl;
		cout << " " << secondplayer->getName() << " defends with " << secondplayer->getArmor() << " armor!";

		secondplayer->defense(attack);
		cout << " Defending " << secondplayer->getName() << " strength after attack: ";
		cout << secondplayer->getStrength() << endl;

		if (secondplayer->getStrength() > 0) {
			cout << endl << secondplayer->getName() << " attacks!";
			int attack2 = secondplayer->attack();

			//cout << "\n Attack: " << attack2 << endl;

			//cout << " Defending " << firstplayer->getName() << " strength: " << firstplayer->getStrength() << endl;
			cout << " " << firstplayer->getName() << " defends with " << firstplayer->getArmor() << " armor!";

			firstplayer->defense(attack2);

			cout << " Defending " << firstplayer->getName() << " strength after attack: " << firstplayer->getStrength() << endl;

		}
	}

	if (firstplayer->getStrength() <= 0) {
		cout << firstplayer->getName() << " " << firstplayer->getIdentity() << " is the loser" << endl;
		cout << secondplayer->getName() << " " << secondplayer->getIdentity() << " is the winner" << endl;
		if (dieRoll == 1) {
			loserstack->add(firstplayer);
			secondplayer->restoreDamage();
			team2->add(secondplayer);
		}

		else {
			loserstack->add(firstplayer);
			secondplayer->restoreDamage();
			team1->add(secondplayer);
		}

	}

	if (secondplayer->getStrength() <= 0) {
		cout << secondplayer->getName() << " " << secondplayer->getIdentity() << " is the loser" << endl;
		cout << firstplayer->getName() << " " << firstplayer->getIdentity() << " is the winner" << endl;
		if (dieRoll == 1) {
			loserstack->add(secondplayer);
			firstplayer->restoreDamage();
			team1->add(firstplayer);
		}

		else {
			loserstack->add(secondplayer);
			firstplayer->restoreDamage();
			team2->add(firstplayer);
		}

	}

}

void PlayGame::finalResults(Queue* team1, Queue* team2, Stack* loserstack) {

	cout << endl;
	cout << "Players left in Team 1:  " << endl;
	team1->display();
	
	cout << endl;
	cout << "Players left in Team 2: " << endl;
	team2->display();

	cout << endl;
	cout << "Losers: " << endl;
	loserstack->display();

	cout << endl;
	cout << "The winning Team is: " << endl;
	if (team1->isEmpty() == true) {
		cout << "Team 2 won the match." << endl << endl;
	}
	else {
		cout << "Team 1 won the match." << endl << endl;
	}

	cout << "First place goes to";
	if (team1->isEmpty() == true) {
		cout << " the surviving players of Team 2: " << endl;
		team2->display();
	}
	else {
		cout << " the surviving players of Team 1:" << endl;
		team1->display();
	}

	cout << endl << "Second place goes to the longest survivor: " << endl;
	loserstack->remove();
	cout << endl;

	cout << "Third place goes to the next survivor: " << endl;
	loserstack->remove();
	loserstack->remove();
	loserstack->remove();
	cout << endl;

}