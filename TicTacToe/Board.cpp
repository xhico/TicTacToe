// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "Board.h"


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

Board::Board() : Matrix() {
	//console[0][0].Set_P();
	//fazer os outros 8
}

Board::Board(char newmatriz[3][3])
	: Matrix(newmatriz) {
}

Board::~Board() {
}

void Board::Go2xy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void Board::Draw_board() {
	cout << "     |     |" << endl
		<< "  " << this->Get_matrix_position(0, 0) << "  |  " << this->Get_matrix_position(0, 1) << "  |  " << this->Get_matrix_position(0, 2) << endl
		<< "     |     |" << endl
		<< "-----+-----+-----" << endl
		<< "     |     |" << endl
		<< "  " << this->Get_matrix_position(1, 0) << "  |  " << this->Get_matrix_position(1, 1) << "  |  " << this->Get_matrix_position(1, 2) << endl
		<< "     |     |" << endl
		<< "-----+-----+-----" << endl
		<< "     |     |" << endl
		<< "  " << this->Get_matrix_position(2, 0) << "  |  " << this->Get_matrix_position(2, 1) << "  |  " << this->Get_matrix_position(2, 2) << endl
		<< "     |     |" << endl;
}

void Board::Draw_board_go2xy() {
	// desenhar o Board com o go2xy
	// apagar linhas etc
	// para alem deste metodo depois fazer o insert symbol com go2xy
	// que é diferente do normal.
}