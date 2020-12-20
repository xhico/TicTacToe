// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include "pch.h"
#include <Windows.h>
#include "Matrix.h"

using namespace std;

class Board : public Matrix {
public:
	Board();
	Board(char newmatriz[3][3]);
	~Board();

	void Go2xy(int x, int y);
	void Draw_board();
	void Draw_board_go2xy();
};



