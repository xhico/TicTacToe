// Nome: Francisco Filipe
// AL 66613
// TIC

#pragma once
#include <iostream>
#include <fstream>
#include "Cell.h"

class Matrix {
private:
	char matrix[3][3];

public:
	Matrix();
	Matrix(char new_matrix[3][3]);
	~Matrix();

	void Set_matrix(char new_matrix[3][3]);
	bool Set_matrix_position(char newPosition, Cell point);

	char Get_matrix_position(int i, int j) { return this->matrix[i][j]; }
	char Get_matrix_position(Cell point) { return this->matrix[point.Get_x()][point.Get_y()]; }
	bool Check_position(Cell point);
	
	void Save(ofstream &os);
	void Read(ifstream &is);
	void operator=(const Matrix newmat);
};

