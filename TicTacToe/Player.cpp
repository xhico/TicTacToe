// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "Player.h"


Player::Player() : User() {
	experience = 0;
	total_games = 0;
	games_won = 0;
}

Player::Player(char newsymbol, string newname, Cell newchoices[5], int newplayed, float newexperience, float newtotal_games, float newgames_won)
	:User(newsymbol, newname, newchoices, newplayed) {
	experience = newexperience;
	total_games = newtotal_games;
	games_won = newgames_won;
}

Player::~Player() {
}

Cell Player::Play(bool valid) {
	int aux = this->Get_Played();

	//check if the last play was valid or the last coords that the player choose were already taken
	if (valid) //coords not taken = last play valid
	{
		aux++;
		this->Set_Played(aux);
	}

	cout << this->Get_Name() << " make your play: " << endl;
	Cell auxp; //aux to help make the play
	while (!auxp.Ask2Set_P()) {
		cout << "Choose only between 1 and 3. Insert new coordenates" << endl;
	}

	this->Set_Choices(auxp, aux);	//add the position to plays history
	return auxp;
}

void Player::Add_Game(int option) {
	if (option == 0)				//player loses game
		this->total_games++;
	else if (option == 1)			//player wins game
	{
		this->total_games++;
		this->games_won++;
	}
}

void Player::Calculate_experiencia(int option) {
	this->Add_Game(option);
	this->experience = this->games_won / this->total_games;
}

void Player::Show() {
	cout << "Nome: " << this->Get_Name() << endl
		<< "Jogos jogados: " << this->total_games << endl
		<< "Vitorias (%): " << this->experience << endl << endl;
}

void Player::operator=(Player newp) {
	this->experience = newp.experience;
	this->total_games = newp.total_games;
	this->games_won = newp.games_won;
	User::Set_Name(newp.Get_Name());
	for (int i = 0; i < 5; i++)
		User::Set_Choices(newp.Get_Choices(i), i);
	User::Set_Played(newp.Get_Played());
	User::Set_Symbol(newp.Get_Symbol());
}

void Player::Save(ofstream &os) {
	User::Save(os);
	os << this->experience << ";" << this->total_games << ";" << this->games_won << endl;
}

void Player::Read(ifstream &is) {
	User::Read(is);
	is >> this->experience;
	is.ignore(INT16_MAX, ';');
	is >> this->total_games;
	is.ignore(INT16_MAX, ';');
	is >> this->games_won;
}