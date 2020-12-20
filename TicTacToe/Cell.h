// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

class Cell {
private:
	int x;
	int y;

public:
	Cell();
	Cell(int m_x, int m_y);
	virtual ~Cell();

	bool Set_x(int m_x);
	bool Set_y(int m_y);
	void Set_P(int m_x, int m_y) { this->x = m_x; this->y = m_x; }
	void Set_P(Cell m_P) { *(this) = m_P; }
	int Get_x(void) const { return  x; }
	int Get_y(void) const { return  y; }
	bool Ask2Set_P(void);

	bool IsValid(void);
	void ShowPonto(void) { cout << "X: " << this->x << endl << "Y: " << this->y << endl; }
	void Save(ofstream &os) { os << this->x << "," << this->y << ";"; }
	void Read(ifstream &is);

	bool operator == (const Cell ponto) const;
	bool operator != (const Cell ponto) const;
	void operator = (Cell ponto) { this->x = ponto.x; this->y = ponto.y; }
};
