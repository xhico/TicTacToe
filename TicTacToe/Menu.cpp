// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "Menu.h"


Menu::Menu() {
	condition = -1;
	game = Game();
	championship = Champ();
}

Menu::Menu(int newcondition, Game newgame, Champ newchampionship) {
	condition = newcondition;
	game = newgame;
	championship = newchampionship;
}

Menu::~Menu() {
}

void Menu::View_B_Menu() {
	cout << "1 - Play Game" << endl
		<< "2 - How to Play" << endl
		<< "3 - Rules" << endl
		<< "4 - Exit Game" << endl;
}

void Menu::ViewHow2Play() {
	cout << "Each player chooses a coord between 1 and 3." << endl
		<< "The position is filled with the symbol of the player" << endl
		<< "the firt player to get 3 symbol in a line wins" << endl << endl
		<< "Return to Menu: ";
}

void Menu::ViewRules() {
	cout << "The board is a combination of three lines and three columns. " << endl
		<< "The game gives randomly each player a symbol that will be used on the board to show the position that each player selected."
		<< "Usually is an 'o' or an 'x'." << endl
		<< "One at a time will select a free position." << endl
		<< "To win the game, the player needs to get 3 'o' or 3 'x' in a horizontal, vertical or diagonal line." << endl << endl
		<< "Return to Menu: ";
}

int Menu::SelectOption() {
	int option = 0;
	do {
		cout << "Option: ";
		cin >> option;
		if (!this->ValidateOption(option))
			cout << "Insert a value between 1 and " << this->condition << endl;
	} while (!this->ValidateOption(option));
	return option;
}

bool Menu::ValidateOption(int option) {
	if ((option >= 1) && (option <= this->condition)) {
		return true;
	}
	else return false;
}

void Menu::PlayGame() {
	system("CLS");
	this->SetCondition(2);
	cout << "1 - New Game" << endl
		<< "2 - Reload Game" << endl;
	switch (this->SelectOption()) {
	case 1:
		this->NewGame();
		break;
	case 2: // loads last game played;
		this->LoadGame();//game.read;
		break;
	}
}

void Menu::NewGame() {
	int aux, aux2; //help define witch game mode the user choose

	system("CLS");
	cout << "GameMod:" << endl
		<< "	1 - Classic" << endl
		<< "	2 - Championship" << endl;
	this->SetCondition(2);
	aux = this->SelectOption();

	cout << "Number Of Players: " << endl
		<< "	1 - 1 Player" << endl
		<< "	2 - 2 Players" << endl;
	aux2 = this->SelectOption(); // number of players

	if (aux == 1) //classic
	{
		if (aux2 == 1) // vs bot
		{
			this->game.Set_Bot(true);
			this->game.FullReset();
			this->game.Complete_Game(1, -1);
		}
		else if (aux2 == 2) // vs player
		{
			this->game.Set_Bot(false);
			this->game.FullReset();
			this->game.Complete_Game(1, -1);
		}
	}
	else if (aux == 2) //championship
	{
		if (aux2 == 1) //vs bot
		{
			this->championship.Set_Bot(true);
			this->championship.FullReset();
			this->championship.Complete_Game(1, -1);
		}
		else if (aux2 == 2) //vs player
		{
			this->championship.Set_Bot(false);
			this->championship.FullReset();
			this->championship.Complete_Game(1, -1);
		}
	}
}

void Menu::LoadGame() {
	int aux = -1; //aux that saves the file content
	int f2p = -1; //first to play

	ifstream is;
	is.open("mode.txt");

	if (!is.is_open()) {
		cout << "ERROR ficheiro mode.txt (Read);" << endl;
		return;
	}

	if (is.peek() == EOF) //check if there is any save made
	{
		system("CLS");
		cout << "All the previous games were finished.";
		Sleep(3000);
		return;
	}

	is >> aux;
	is.close();

	switch (aux) {
	case 1: // classic vs bot
		this->game.Set_Bot(true);
		f2p = this->game.Read();
		this->game.Complete_Game(3, f2p);
		break;
	case 2:// classic vs player
		this->game.Set_Bot(false);
		f2p = this->game.Read();
		this->game.Complete_Game(3, f2p);
		break;
	case 3: //championship vs bot
		this->championship.Set_Bot(true);
		if (!this->championship.EndedGame(&f2p))
			this->championship.Complete_Game(3, f2p);
		break;
	case 4://championship vs player
		this->championship.Set_Bot(true);
		if (!this->championship.EndedGame(&f2p))
			this->championship.Complete_Game(3, f2p);
		break;
	}
}