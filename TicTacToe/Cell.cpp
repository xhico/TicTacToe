// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "Cell.h"

Cell::Cell() {
	x = -1;
	y = -1;
}

Cell::Cell(int m_x, int m_y) {
	x = m_x;
	y = m_y;
}

Cell::~Cell() {
}

bool Cell::Set_x(int m_x) {
	if ((m_x >= 1) && (m_x <= 3)) {
		this->x = m_x - 1;
		return true;
	}
	else return false;
}

bool Cell::Set_y(int m_y) {
	if ((m_y >= 1) && (m_y <= 3)) {
		this->y = m_y - 1;
		return true;
	}
	else return false;
}

bool Cell::Ask2Set_P(void) {

	cout << "Insira a linha: ";
	cin >> this->x;
	cout << "Insira a coluna: ";
	cin >> this->y;

	return this->IsValid();
}

bool Cell::IsValid(void) {
	if ((this->x <= 3) && (this->x >= 1)
		&& (this->y <= 3) && (this->y >= 1)) {
		this->x--;
		this->y--;
		return true;
	}
	else return false;

}

void Cell::Read(ifstream &is) {
	is >> this->x;
	is.ignore(INT16_MAX, ',');
	is >> this->y;
	is.ignore(INT16_MAX, ';');
}

bool Cell::operator== (const Cell Cell) const {
	if ((this->x == Cell.x)
		&& (this->y == Cell.y)) {
		return true;
	}
	else return false;
}

bool Cell::operator!=(const Cell Cell) const {
	if (*(this) == Cell) {
		return false;
	}
	else return true;
}

