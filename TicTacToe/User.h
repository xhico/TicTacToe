// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Cell.h"

class User {
private:
	string name;				// player name
	char symbol;				// player symbol
	Cell choices[5];			// player plays' history
	int played;					// times played

public:

	User();
	User(char newSymbol, string newName, Cell newChoices[5], int newPlayed);
	~User();

	void Set_Symbol(char newSymbol) { symbol = newSymbol; }
	void Set_Name(string newName) { name = newName; }
	void Set_Played(int newPlayed) { played = newPlayed; }
	void Set_Choices(Cell newChoices[5]);							//set the full vector at once
	void Set_Choices(Cell choice, int i);							//set only 1 play; choice = position that player choose;
	void Set_Choices(int x, int y, int i);							//set by manually insert coordenates

	char Get_Symbol() { return symbol; }
	string Get_Name() { return name; }
	int Get_Played() { return played; }
	Cell Get_Choices(int i) { return choices[i]; }					//return only 1; choose 1 choice between i=1..5

	void Show();
	void Show_plays();
	void Show_plays(int i);
	void Save(ofstream &os);
	void Read(ifstream &is);
	virtual Cell Play(bool valid) = 0;								//user choose a position to put his symbol

	void Game_Reset();
};

