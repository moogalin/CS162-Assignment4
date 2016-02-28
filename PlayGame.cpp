#include "PlayGame.hpp"

PlayGame::PlayGame() {
	team1 = &playerQteam1;
	team2 = &playerQteam2;
	loserstack = &losers;
	playerPtr = NULL;
}

PlayGame::~PlayGame() {
	playerPtr = NULL;
}

Queue* PlayGame::getTeam1() {
	return team1;
}

Queue* PlayGame::getTeam2() {
	return team2;
}

Stack* PlayGame::getLosers() {

	return loserstack;
}

void PlayGame::userPromptPlayers() {

	int players;
	cout << "How many players would you like to begin with on each team?" << endl;
	cout << "Players Per Team: ";
	cin >> players;
	cin.ignore();


	while (players < 1 ) {
		cout << "Each team should have at least one player." << endl;
		cout << "Players Per Team: ";
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

void PlayGame::playGameOutput() {
	int dieRoll = (rand() % 2) + 1;
	Creature * firstplayer;
	Creature * secondplayer;

	// Allow teams to alternate between who begins the attack and who begins the defense. 
	if (dieRoll == 1) {
		firstplayer = team1->remove();
		secondplayer = team2->remove();
	}

	else {
		firstplayer = team2->remove();
		secondplayer = team1->remove();
	}

	int rounds = 0;


	while ((firstplayer->getStrength() > 0) && (secondplayer->getStrength() > 0)) {
		rounds++;

		cout << endl << "Start of round " << rounds << endl;

		int attack = firstplayer->attack();
		cout << " " << firstplayer->getName() << " " << firstplayer->getIdentity() << " rolls attack value of ";
		cout << firstplayer->getattackVal() << endl;

		
		secondplayer->defense(attack);
		cout << " " << secondplayer->getName();
		cout << " " << secondplayer->getIdentity() << " rolls defense value of ";
		cout << secondplayer->getDefenseVal() << " and defends with " << secondplayer->getArmor() << " armor.";

		
		cout << " Defending " << secondplayer->getName() << " " << secondplayer->getIdentity();
		cout << " strength after attack: " << secondplayer->getStrength() << endl;

		if (secondplayer->getStrength() > 0) {
			int attack2 = secondplayer->attack();
			cout << " " << secondplayer->getName();
			cout << " " << secondplayer->getIdentity() << " rolls attack value of ";
			cout << secondplayer->getattackVal() << endl;

			firstplayer->defense(attack2);
			cout << " " << firstplayer->getName() << " rolls defense value of ";
			cout << firstplayer->getDefenseVal() << " and defends with " << firstplayer->getArmor() << " armor!";

			cout << " Defending " << firstplayer->getName() << " " << firstplayer->getIdentity();
			cout << " strength after attack: " << firstplayer->getStrength() << endl;

		}
	}
	if (firstplayer->getStrength() <= 0) {
		cout << " " << firstplayer->getName() << " " << firstplayer->getIdentity() << " is the loser and ";
		cout << secondplayer->getName() << " " << secondplayer->getIdentity() << " is the winner in ";
		cout << rounds << " rounds." << endl;

		if (dieRoll == 1) {
			loserstack->add(firstplayer);
			cout << " " << secondplayer->getName() << " " << secondplayer->getIdentity();
			cout << " restores " << secondplayer->restoreDamage();
			cout << " damage before returning to the lineup!" << endl;
			team2->add(secondplayer);
		}

		else {
			loserstack->add(firstplayer);
			cout << " " << secondplayer->getName() << " " << secondplayer->getIdentity();
			cout << " restores " << secondplayer->restoreDamage();
			cout << " damage before returning to the lineup!" << endl;
			team1->add(secondplayer);
		}

	}

	if (secondplayer->getStrength() <= 0) {
		cout << " " << secondplayer->getName() << " " << secondplayer->getIdentity() << " is the loser and ";
		cout << firstplayer->getName() << " " << firstplayer->getIdentity() << " is the winner in ";
		cout << rounds << " rounds." << endl;

		if (dieRoll == 1) {

			cout << " " << firstplayer->getName() << " " << firstplayer->getIdentity();
			cout << " restores " << firstplayer->restoreDamage();
			cout << " damage before returning to the lineup!" << endl;

			loserstack->add(secondplayer);
			team1->add(firstplayer);
		}

		else {
			cout << " " << firstplayer->getName() << " " << firstplayer->getIdentity();
			cout << " restores " << firstplayer->restoreDamage();
			cout << " damage before returning to the lineup!" << endl;

			loserstack->add(secondplayer);
			team2->add(firstplayer);
		}

	}

}

void PlayGame::playGame() {
	int dieRoll = (rand() % 2) + 1;
	Creature * firstplayer;
	Creature * secondplayer;


	// Allow teams to alternate between who begins the attack and who begins the defense. 
	if (dieRoll == 1) {
		firstplayer = team1->remove();
		secondplayer = team2->remove();

	}

	else {
		firstplayer = team2->remove();
		secondplayer = team1->remove();
	}

	cout << firstplayer->getName() << " " << firstplayer->getIdentity() << " vs. ";
	cout << secondplayer->getName() << " " << secondplayer->getIdentity() << endl;

	int rounds = 0;


	while ((firstplayer->getStrength() > 0) && (secondplayer->getStrength() > 0)) {
		rounds++;

		int attack = firstplayer->attack();

		secondplayer->defense(attack);

		if (secondplayer->getStrength() > 0) {

			int attack2 = secondplayer->attack();

			firstplayer->defense(attack2);

		}
	}

	if (firstplayer->getStrength() <= 0) {
		cout << " " << firstplayer->getName() << " " << firstplayer->getIdentity() << " is the loser and ";
		cout << secondplayer->getName() << " " << secondplayer->getIdentity() << " is the winner in ";
		cout << rounds << " rounds." << endl;

		if (dieRoll == 1) {
			loserstack->add(firstplayer);
			cout << " " << secondplayer->getName() << " " << secondplayer->getIdentity();
			cout << " restores " << secondplayer->restoreDamage();
			cout << " damage before returning to the lineup!" << endl;
			team2->add(secondplayer);
		}

		else {
			loserstack->add(firstplayer);
			cout << " " << secondplayer->getName() << " " << secondplayer->getIdentity();
			cout << " restores " << secondplayer->restoreDamage();
			cout << " damage before returning to the lineup!" << endl;
			team1->add(secondplayer);
		}

	}

	if (secondplayer->getStrength() <= 0) {
		cout << " " << secondplayer->getName() << " " << secondplayer->getIdentity() << " is the loser and ";
		cout << firstplayer->getName() << " " << firstplayer->getIdentity() << " is the winner in ";
		cout << rounds << " rounds." << endl;

		if (dieRoll == 1) {

			cout << " " << firstplayer->getName() << " " << firstplayer->getIdentity();
			cout << " restores " << firstplayer->restoreDamage();
			cout << " damage before returning to the lineup!" << endl;

			loserstack->add(secondplayer);
			team1->add(firstplayer);
		}

		else {
			cout << " " << firstplayer->getName() << " " << firstplayer->getIdentity();
			cout << " restores " << firstplayer->restoreDamage();
			cout << " damage before returning to the lineup!" << endl;

			loserstack->add(secondplayer);
			team2->add(firstplayer);
		}

	}

}

void PlayGame::finalResults() {

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
	cout << endl;




}