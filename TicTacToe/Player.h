// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include "User.h"

class Player : public User {
private:
	float experience;	//% of games that player won
	float total_games;	//total games played
	float games_won;	//total games won

public:
	Player();
	Player(char newSymbol, string newName, Cell newChoices[5], int newPlayed, float newExperience, float newTotal_games, float neGames_won);
	~Player();

	void Set_experiencia(float newExperience) { this->experience = newExperience; }
	void Set_total_games(float newTotal_games) { this->total_games = newTotal_games; }
	void Set_games_won(float newgames_won) { this->games_won = newgames_won; }

	float Get_experiencia() { return this->experience; }
	float Get_total_games() { return this->total_games; }
	float Get_games_won() { return this->games_won; }

	Cell Play(bool valid);						//player choose position to play

	void Add_Game(int option);					//option = 0 - player loses game; option = 1 - player wins game;
	void Calculate_experiencia(int option);		//calculate % of wins; option from Add_Game; option = Add_Game option
	void Show();
	void operator=(const Player newp);
	void Save(ofstream &os);
	void Read(ifstream &is);
};

