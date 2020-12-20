// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "Bot.h"


Bot::Bot() : User() {
	this->Set_Name("Jarvis");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = '-';
		}
	}
}

Bot::Bot(char newSymbol, Cell newChoices[5], int newPlayed) : User(newSymbol, "Jarvis", newChoices, newPlayed) {
}

Bot::~Bot() {
}

Cell Bot::Play(bool valid) {
	int x = -1;
	int y = -1;
	int aux = User::Get_Played();

	//check if the last play was valid or the last coords that the player choose were already taken
	//coords not taken = last play valid
	if (valid) {
		aux++;
		User::Set_Played(aux);
	}

	do {
		srand(time(NULL));
		x = rand() % 3;
		y = rand() % 3;
		User::Set_Choices(x, y, aux);	// generate coordenates
	} while (this->matrix[x][y] == 'x');

	if (this->matrix[x][y] == '-')		// check if the bot already tried these coords
		this->matrix[x][y] = 'x';

	return User::Get_Choices(aux);
}

void Bot::operator=(Bot newb) {
	for (int i = 0; i < 5; i++)
		User::Set_Choices(newb.Get_Choices(i), i);
	User::Set_Played(newb.Get_Played());
	User::Set_Symbol(newb.Get_Symbol());
	User::Set_Name(newb.Get_Name());
}

void Bot::Reset() {
	User::Game_Reset();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = '-';
		}
	}
}