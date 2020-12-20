// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include "Cell.h"
#include "Board.h"
#include "Player.h"
#include "BOT.h"
using namespace std;

class Game {
private:
	bool bot;

protected:
	Player player1, player2;
	Bot bot1;
	int count;						// Posicoes ja ocupdas
	Board tab;

public:
	Game();
	Game(Board newtab, Player newplayer1, Player newplayer2, Bot newb1, int newcount, bool newbot);
	~Game();

	void Set_Tab(Board newtab) { this->tab = newtab; }
	void Set_P1(Player newplayer1) { this->player1 = newplayer1; }
	void Set_P2(Player newplayer2) { this->player2 = newplayer2; }
	void Set_B1(Bot newbot) { this->bot1 = newbot; }
	void Set_Count(int newcount) { this->count = newcount; }
	void Set_Bot(bool newbot) { this->bot = newbot; }
	int Get_Count() { return this->count; }
	bool Get_Bot() { return this->bot; }
	Board Get_Tab() { return this->tab; }
	Player Get_P1() { return this->player1; }
	Player Get_P2() { return this->player2; }
	Bot Get_B1() { return this->bot1; }

	void Set_Player_Name();
	void Set_Players_Symbol();
	void FullReset();
	int First2Play();
	int Begin_Game(int option);
	virtual void Save_Mode();
	void Make_Play(int aux);
	char Check_Winner();
	void Validate_Winner(char caux);
	void ResetGame();
	int Play_Again();
	void Show_Player_Stats();
	void Empty_Save_File();
	virtual void Complete_Game(int option, int f2p);

	virtual int Read();
	virtual void Save(int aux);
	void operator=(const Game newgame);
};