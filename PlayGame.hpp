
#include "Barbarian.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "LoserStack.hpp"
#include "PlayerQueue.hpp"




class PlayGame {
private:
	int playersPerTeam;
	Creature * playerPtr;
	Stack losers;
	Queue playerQteam1;
	Queue playerQteam2;
	Queue * team1;
	Queue * team2;
	Stack * loserstack;


public:
	PlayGame();
	~PlayGame();
	Queue * getTeam1(); 
	Queue * getTeam2(); 
	Stack * getLosers(); 
	void userPromptPlayers();
	void createTeams(Queue* teamID, string teamName);
	char playerMenu();
	void playGame();
	void playGameOutput();
	void finalResults();


};
