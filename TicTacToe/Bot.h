// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include "User.h"
#include <time.h>

class Bot : public User {
private:
	char matrix[3][3];				// Verifica se ja jogou na casa

public:
	Bot();
	Bot(char newsymbol, Cell newchoices[5], int newplayed);
	~Bot();

	Cell Play(bool valid);

	void operator=(Bot newb);
	void Reset();
};
