// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include "Game.h"

using namespace std;

class Champ : public Game {
private:
	int c1, c2;			//wins para cada player
	int countgame;

public:
	Champ();
	Champ(int newc1, int newc2, int newcount, int newcountgames, Player newp1, Player newp2, Bot newb1, Board newtab, bool newbot);
	~Champ();

	void Set_C1(int newc1) { this->c1 = newc1; }
	int Get_C1() { return this->c1; }
	void Set_C2(int newc2) { this->c2 = newc2; }
	int Get_C2() { return this->c2; }
	void Set_Countgames(int newcountgames) { this->countgame = newcountgames; }
	int Get_Countgames() { return this->countgame; }

	void FullReset();

	void operator=(Champ newchamp);
	int Read();
	void Save(int aux);
	void Save_Mode();

	bool EndedGame(int *aux);		// jogo ja acabou?
	void Validate_Game_Winner(char caux, int *aux);
	void Validate_Winner();			// ganhou champ
	void Show_score(int i);
	void ResetGame();
	void Complete_Game(int option, int f2p);
};

