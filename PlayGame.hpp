
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
	Queue * ptrTeam1;
	Queue * ptrTeam2;
	Stack * ptrLosers;


public:
	PlayGame(const PlayGame &obj);
	PlayGame();
	~PlayGame();
	Queue * getTeam1();
	Queue * getTeam2();
	Stack * getLosers();
	void userPromptPlayers();
	void createTeams(Queue*, string);
	char playerMenu();
	void playGame(Queue* team1, Queue* team2, Stack* loserstack);
	void finalResults(Queue* team1, Queue* team2, Stack* loserstack);


};
