// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include "Champ.h"
#include "Game.h"

using namespace std;

class Menu {
private:
	int condition;
	Game game;
	Champ championship;

public:
	Menu();
	Menu(int newcondition, Game newgame, Champ newchampionship);
	~Menu();

	void SetCondition(int newcondition) { this->condition = newcondition; }
	int GetCondition() { return this->condition; }
	void SetGame(Game newgame) { this->game = newgame; }
	Game GetGame() { return this->game; }
	void SetChampionship(Champ newchampionship) { this->championship = newchampionship; }
	Champ GetChampionship() { return this->championship; }

	void View_B_Menu();
	void ViewHow2Play();
	void ViewRules();
	int SelectOption();
	bool ValidateOption(int option);
	void PlayGame();
	void NewGame();
	void LoadGame();
};

