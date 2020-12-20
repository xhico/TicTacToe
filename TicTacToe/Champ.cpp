// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "Champ.h"


Champ::Champ() {
	Game::Game();
	c1 = 0;
	c2 = 0;
	countgame = 1;
}

Champ::Champ(int newc1, int newc2, int newcount, int newcountgames, Player newp1, Player newp2, Bot newb1, Board newtab, bool newbot)
	:Game(newtab, newp1, newp2, newb1, newcount, newbot) {
	c1 = newc1;
	c2 = newc2;
	countgame = newcountgames;
}

Champ::~Champ() {
}

void Champ::ResetGame() {
	Game::ResetGame();
	this->c1 = 0;
	this->c2 = 0;
}

void Champ::FullReset() {
	Game::FullReset();
	Champ();
}

void Champ::Validate_Game_Winner(char caux, int *aux) {

	Game::Validate_Winner(caux);
	if (caux == Game::player1.Get_Symbol()) {
		this->c1++;
		*aux = 1;		// as player1 won the last game, he is the first to play next game
	}
	else if (((caux == Game::player2.Get_Symbol()) && (!Game::Get_Bot()))
			 || ((caux == Game::bot1.Get_Symbol()) && (Game::Get_Bot()))) {
		this->c2++;
		*aux = 0;		// as player2 or bot won the last game, they are the first to play next game
	}
}

void Champ::Validate_Winner() {
	if (this->c1 > this->c2) {
		if (Game::Get_Bot()) {
			cout << "1º Lugar: " << Game::player1.Get_Name() << endl;
			cout << "2º Lugar: " << bot1.Get_Name() << endl;
		}
		else if (!Game::Get_Bot()) {
			cout << "1º Lugar: " << Game::player1.Get_Name() << endl;
			cout << "2º Lugar: " << Game::player2.Get_Name() << endl;
		}
	}
	else if (this->c1 < this->c2) {
		if (Game::Get_Bot()) {
			cout << "1º Lugar: Computador" << endl;
			cout << "2º Lugar: " << Game::player1.Get_Name() << endl;
		}
		else if (!Game::Get_Bot()) {
			cout << "1º Lugar: " << Game::player2.Get_Name() << endl;
			cout << "2º Lugar: " << Game::player1.Get_Name() << endl;
		}
	}
	else if (this->c1 == this->c2)
		cout << "Champ empatado" << endl;

	Sleep(2000);
}

void Champ::Show_score(int i) {
	cout << Game::player1.Get_Name() << " tem " << c1 << " vitorias em " << i << " jogos." << endl;
	if (!Game::Get_Bot())//player2
	{
		cout << Game::player2.Get_Name() << " tem " << c2 << " vitorias em " << i << " jogos." << endl;
	}
	else if (Game::Get_Bot()) //bot1
	{
		cout << bot1.Get_Name() << " tem " << c2 << " vitorias em " << i << " jogos." << endl;
	}
}

void Champ::Save(int aux) {
	ofstream os;

	os.open("reload_game.txt");

	if (!os.is_open())
		return;

	os << this->countgame << ";" << Game::count << ";" << aux << endl; //game state

	if (Game::Get_Bot()) {//player info
		Game::player1.Save(os);
		Game::bot1.Save(os);
	}
	else {//player info
		Game::player1.Save(os);
		Game::player2.Save(os);
	}
	Game::tab.Save(os); //board state

	os.close();
}

void Champ::Complete_Game(int option, int f2p) {
	int auxoption = option;
	int aux = -2;	// aux that helps identify who play first
	char caux;		// aux that help identify the winner

	this->Save_Mode(); //save game mode;

	do {
		system("CLS");

		//begin
		if (f2p == -1)  //newgame
			aux = Game::Begin_Game(auxoption); // select the way to start the game
		else if (f2p == 0 || f2p == 1) //saved game
			aux = f2p;

		//Mid Game
		for (this->countgame; this->countgame < 11; this->countgame++) //championship games
		{
			caux = '?';

			//anounce the game.
			if (Game::count == 0) {
				cout << "Game " << this->countgame << " is starting..." << endl;
				Sleep(3000);
			}
			system("CLS");
			Game::tab.Draw_board();

			do //game
			{
				Game::count++;
				Game::Make_Play(aux); //players make thier plays
				system("CLS");
				Game::tab.Draw_board();
				this->Save(aux); // save automatically the game each time a player plays

				if (Game::count >= 5)
					caux = Game::Check_Winner(); //check if there is any winner
			} while ((Game::count < 9) && (caux == '?'));

			this->Validate_Game_Winner(caux, &aux); //validate game winner
			system("CLS");
			this->Show_score(this->countgame); // show player score
			this->Save(aux); //at the final stage of each game, the game changes somethings so this save is needed
			Game::ResetGame(); // reset game
			system("PAUSE");
		}

		//End Game
		this->Validate_Winner();
		Game::Empty_Save_File(); //empty the file because game was finished
		this->ResetGame();
	} while ((auxoption = Game::Play_Again()) == 2);
}

int Champ::Read() {
	int aux;
	ifstream is;

	is.open("reload_game.txt");

	if (!is.is_open()) {
		cout << "ERROR ficheiro reload_game.txt(read)";
		return -1;
	}

	is >> this->countgame;
	is.ignore(INT16_MAX, ';');
	is >> Game::count;
	is.ignore(INT16_MAX, ';');
	is >> aux;
	if (Game::Get_Bot()) {
		this->player1.Read(is);
		this->bot1.Read(is);
	}
	else if (!Game::Get_Bot()) {
		this->player1.Read(is);
		this->player2.Read(is);
	}
	this->tab.Read(is);
	is.close();

	return aux;
}

bool Champ::EndedGame(int *aux) {
	*aux = this->Read();
	if (this->countgame == 10) //check if championship is finished
	{
		if ((Game::count == 9)
			|| (Game::Check_Winner() == 'O')
			|| (Game::Check_Winner() == 'X')) {
			cout << "All the games were finished!" << endl;
			Sleep(5);
			return true;
		}
	}
	else {
		if ((Game::count == 9)
			|| (Game::Check_Winner() == 'O')
			|| (Game::Check_Winner() == 'X')) //check if game is finished
		{
			this->countgame++;
			Game::ResetGame();
		}
		return false;
	}
}

void Champ::operator=(Champ newchamp) {
	this->player1 = newchamp.player1;
	this->player2 = newchamp.player2;
	this->bot1 = newchamp.bot1;
	this->Set_Bot(newchamp.Get_Bot());
	this->count = newchamp.count;
	this->tab = newchamp.tab;
	this->c1 = newchamp.c1;
	this->c2 = newchamp.c2;
	this->countgame = newchamp.countgame;
}

void Champ::Save_Mode() {
	ofstream os;

	os.open("mode.txt");
	if (!os.is_open()) {
		cout << "ERROR ficheiro mode.txt (save)" << endl;
		return;
	}

	if (this->Get_Bot() == true) //vs bot
		os << "3";
	else //vs player
		os << "4";

	os.close();
}