// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "Game.h"


Game::Game() {
	tab = Board();
	player1 = Player();
	player2 = Player();
	bot1 = Bot();
	count = 0;
	bot = false;
}

Game::Game(Board newtab, Player newplayer1, Player newplayer2, Bot newb1, int newcount, bool newBot) {
	tab = newtab;
	player1 = newplayer1;
	player2 = newplayer2;
	bot1 = newb1;
	count = newcount;
	bot = newBot;
}

Game::~Game() {
}

int Game::First2Play() {
	int aux;

	if (player1.Get_Symbol() == 'X') {
		aux = 1;
	}
	else {
		aux = 2;
	}

	return aux;
}

void Game::Set_Player_Name() {
	string aux;
	cout << "Nome do player1: ";
	cin.ignore(INT16_MAX, '\n');
	getline(cin, aux);
	this->player1.Set_Name(aux);

	if (!this->bot) {
		cout << "Nome do player2: ";
		getline(cin, aux);
		this->player2.Set_Name(aux);
	}
}

void Game::Set_Players_Symbol() {
	srand(time(NULL));
	if ((rand() % 2) == 1) {
		cout << this->player1.Get_Name() << " e o 'O'." << endl;
		this->player1.Set_Symbol('O');
		if (!this->bot) {
			cout << this->player2.Get_Name() << " e o 'X'." << endl;
			this->player2.Set_Symbol('X');
		}
		else {
			cout << bot1.Get_Name() << " e o 'X'." << endl;
			this->bot1.Set_Symbol('X');
		}

	}
	else {
		cout << this->player1.Get_Name() << " e o 'X'." << endl;
		this->player1.Set_Symbol('X');
		if (!this->bot) {
			cout << this->player2.Get_Name() << " e o 'O'." << endl;
			this->player2.Set_Symbol('O');
		}
		else {
			cout << bot1.Get_Name() << " e o 'O'." << endl;
			this->bot1.Set_Symbol('O');
		}
	}
}

int Game::Begin_Game(int option) {
	if (option == 1)				//newgame
	{
		this->Set_Player_Name();
		this->Set_Players_Symbol();
		return this->First2Play();
	}
	else // play agian
		return this->First2Play();
}

char Game::Check_Winner() {
	for (int i = 0; i < 3; i++) {
		//horizontal
		if ((this->tab.Get_matrix_position(i, 0) == this->tab.Get_matrix_position(i, 1)) && (this->tab.Get_matrix_position(i, 0) == this->tab.Get_matrix_position(i, 2))
			&& (this->tab.Get_matrix_position(i, 0) == 'O' || this->tab.Get_matrix_position(i, 0) == 'X')) {
			return this->tab.Get_matrix_position(i, 0);
		}
		//vertical
		if (this->tab.Get_matrix_position(0, i) == this->tab.Get_matrix_position(1, i) && (this->tab.Get_matrix_position(0, i) == this->tab.Get_matrix_position(2, i))
			&& (this->tab.Get_matrix_position(0, i) == 'O' || this->tab.Get_matrix_position(0, i) == 'X')) {
			return this->tab.Get_matrix_position(0, i);
		}
	}

	//diagonal
	if ((this->tab.Get_matrix_position(1, 1) == this->tab.Get_matrix_position(2, 2) && this->tab.Get_matrix_position(1, 1) == this->tab.Get_matrix_position(0, 0))
		|| (this->tab.Get_matrix_position(2, 0) == this->tab.Get_matrix_position(1, 1) && (this->tab.Get_matrix_position(2, 0) == this->tab.Get_matrix_position(0, 2)))
		&& (this->tab.Get_matrix_position(1, 1) == 'O' || this->tab.Get_matrix_position(1, 1) == 'X')) {
		return this->tab.Get_matrix_position(1, 1);
	}
	else return '?';
}

void Game::Validate_Winner(char caux) {

	// Empate
	if (caux == '?') {
		cout << "Empate!!" << endl;

		// joga comtra bot
		if (this->bot)
			this->player1.Calculate_experiencia(0); // exp do player1
		
		// se jogam 2 players
		else if (!this->bot) {
			this->player1.Calculate_experiencia(0); // exp do player1
			this->player2.Calculate_experiencia(0); // exp do player2
		}
	}

	//player1 wins
	if (caux == this->player1.Get_Symbol()) {
		cout << this->player1.Get_Name() << " GANHOU!" << endl;
		this->player1.Calculate_experiencia(1);

		//if are playing 2 players
		if (!this->bot)
			this->player2.Calculate_experiencia(0);
	}


	//if player2 or bot1 wins
	if (this->bot) //playing with Bot
	{
		//bot1 wins
		if (caux == this->bot1.Get_Symbol()) {
			cout << bot1.Get_Name()  << " GANHOU!" << endl;
			this->player1.Calculate_experiencia(0);
		}
	}

	else if (!this->bot)  // playing with player2
	{
		//player2 wins
		if (caux == this->player2.Get_Symbol()) {
			cout << this->player2.Get_Name() << " GANHOU!" << endl;
			this->player2.Calculate_experiencia(1);
			this->player1.Calculate_experiencia(0);
		}
	}
	Sleep(2000);
}

void Game::Save(int aux) {
	ofstream os;

	//open file
	os.open("reload_game.txt");

	if (!os.is_open())
		return;

	os << this->count << ";" << aux << endl;

	//players info
	if (this->bot) { 
		this->player1.Save(os);
		this->bot1.Save(os);
	}
	else {
		this->player1.Save(os);
		this->player2.Save(os);
	}
	this->tab.Save(os);
	os.close();
}

int Game::Read() {
	int aux;
	ifstream is;

	is.open("reload_game.txt");

	if (!is.is_open())
		return -1;

	is >> this->count;
	is.ignore(INT16_MAX, ';');
	is >> aux;
	if (this->bot) {
		this->player1.Read(is);
		this->bot1.Read(is);
	}
	else if (!this->bot) {
		this->player1.Read(is);
		this->player2.Read(is);
	}
	this->tab.Read(is);
	is.close();

	return aux;
}

void Game::ResetGame() {
	this->tab = Board();
	this->count = 0;
	this->player1.Game_Reset();
	if (this->bot)
		this->bot1.Reset();
	else
		this->player2.Game_Reset();
}

void Game::FullReset() {
	Game();
}

void Game::Complete_Game(int option, int f2p) {
	int auxoption = option;
	int aux = -1;	// aux that helps decido who's playing 
	char caux;		// aux that helps identify who won

	do {
		this->Save_Mode();		//save game mode;
		system("CLS");
		caux = '?';				// reset var

		//begin
		if (f2p == -1)			//newgame
			aux = this->Begin_Game(auxoption);	// select the way to start the game
		else if (f2p == 0 || f2p == 1)			// saved game
			aux = f2p;

		this->tab.Draw_board();

		//Mid Game
		do {
			this->count++;
			this->Make_Play(aux);	// players make thier plays
			system("CLS");
			this->tab.Draw_board();
			this->Save(aux);		// save automatically the game

			if (this->count >= 5)
				caux = this->Check_Winner(); //check if there is any winner
		} while ((this->count < 9) && (caux == '?'));

		//End Game
		this->Validate_Winner(caux);	// validate winner
		this->Empty_Save_File();		// empty the file because game was finished
		this->ResetGame();
	} while ((auxoption = this->Play_Again()) == 1);
}

void Game::Make_Play(int aux) {
	bool valid = true;

	// player1 time to play
	if ((this->count + aux) % 2 == 0) {
		//make a play. check if position is valid and free
		while (!this->tab.Set_matrix_position(this->player1.Get_Symbol(), this->player1.Play(valid))) {
			valid = false;
			cout << "Insira uma posicao vazia!" << endl;
		}
	}

	//player2 or bot1 time to play
	else if ((this->count + aux) % 2 == 1) { 
		//Bot time to play
		if (this->bot) {
			int i = 0;
			while (!this->tab.Set_matrix_position(this->bot1.Get_Symbol(), this->bot1.Play(valid))) {
				i++;
				valid = false;
				if (i == 10)
					cout << bot1.Get_Name() << " esta um pouco lento" << endl;
			}
		}
		
		// player time to play
		else if (!this->bot) {
			// make a play. check if position is valid and free
			while (!this->tab.Set_matrix_position(this->player2.Get_Symbol(), this->player2.Play(valid))) {
				valid = false;
				cout << "Insira uma posicao vazia!" << endl;
			}
		}
	}
}

int Game::Play_Again() {
	int aux;

	do {
		do {
			system("CLS");
			cout << "1 - Play again" << endl
				<< "2 - Check Player Stats" << endl
				<< "3 - Return to Menu" << endl
				<< " Option: ";
			cin >> aux;

			// player stats
			if (aux == 2)
				this->Show_Player_Stats();
		} while (aux == 2);

		//validate option
		if (aux < 1 || aux > 3) {
			cout << "Insert a valid option;";
			Sleep(2000);
		}
	} while (aux < 1 || aux > 3);
	return aux++; // +1 because on begin_game, the option 2 is play again;
}

void Game::operator=(const Game newgame) {
	this->player1 = newgame.player1;
	this->player2 = newgame.player2;
	this->bot1 = newgame.bot1;
	this->bot = newgame.bot;
	this->count = newgame.count;
	this->tab = newgame.tab;
}

void Game::Save_Mode() {
	ofstream os;

	os.open("mode.txt");
	if (!os.is_open()) {
		cout << "ERROR ficheiro mode.txt (save)" << endl;
		return;
	}

	if (this->bot == true) 
		os << "1";
	else
		os << "2";

	os.close();
}

void Game::Show_Player_Stats() {
	system("CLS");
	this->player1.Show();
	if (!this->bot)
		this->player2.Show();

	system("PAUSE");
}

void Game::Empty_Save_File() {
	ofstream os;

	os.open("reload_game.txt");

	if (!os.is_open()) {
		cout << "ERROR file reload_game(empty)" << endl;
		return;
	}

	os.close();

	os.open("mode.txt");

	if (!os.is_open()) {
		cout << "ERROR file mode.txt(empty)";
		return;
	}

	os.close();
}
