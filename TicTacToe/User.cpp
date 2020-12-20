// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "User.h"


User::User() {
	symbol = '-';
	name = "-";
	played = -1;
	for (int i = 0; i < 5; i++) {
		choices[i] = Cell();
	}
}

User::User(char newSymbol, string newName, Cell newChoices[5], int newPlayed) {
	name = newName;
	symbol = newSymbol;
	played = newPlayed;
	for (int i = 0; i < 5; i++) {
		choices[i] = newChoices[i];
	}
}

User::~User() {
}

void User::Set_Choices(Cell newChoices[5]) {
	for (int i = 0; i < 5; i++) {
		this->choices[i] = newChoices[i];
	}
}

void User::Set_Choices(Cell choice, int i) {
	choices[i] = choice;
}

void User::Set_Choices(int x, int y, int i) {
	this->choices[i].Set_x(x + 1);
	this->choices[i].Set_y(y + 1);
}

void User::Show() {
	cout << this->name << " - Plays with " << this->symbol << endl;
}

void User::Show_plays() {
	cout << "During the game, " << this->name << " choose the following position: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << i << " - " << choices[i].Get_x() + 1 << ";" << choices[i].Get_y() + 1 << endl;
	}
}

void User::Show_plays(int i) {
	cout << "x - " << this->choices[i].Get_x() + 1 << endl
		<< "y - " << this->choices[i].Get_y() + 1 << endl;
}

void User::Save(ofstream &os) {
	os << this->name << ";" << this->symbol << ";" << this->played + 1 << ";" << endl;
	for (int i = 0; i <= played; i++) {
		this->choices[i].Save(os);
	}
	os << endl;
}

void User::Read(ifstream &is) {
	getline(is, this->name, ';');
	is >> this->symbol;
	is.ignore(INT16_MAX, ';');
	is >> this->played;
	is.ignore(INT16_MAX, ';');
	for (int i = 0; i < this->played; i++) {
		this->choices[i].Read(is);
	}
}

void User::Game_Reset() {
	this->played = -1;
	for (int i = 0; i < 5; i++) {
		this->choices[i] = Cell();
	}
}