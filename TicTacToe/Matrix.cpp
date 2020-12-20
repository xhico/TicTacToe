// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include "Matrix.h"


Matrix::Matrix() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = '-';
		}
	}
}

Matrix::Matrix(char new_matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = new_matrix[i][j];
		}
	}
}

Matrix::~Matrix() {
}

void Matrix::Set_matrix(char new_matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->matrix[i][j] = new_matrix[i][j];
		}
	}
}

bool Matrix::Set_matrix_position(char new_position, Cell point) {
	if (this->Check_position(point)) {
		this->matrix[point.Get_x()][point.Get_y()] = new_position;
		return true;
	}
	else return false;
}

bool Matrix::Check_position(Cell point) {
	if (this->matrix[point.Get_x()][point.Get_y()] == '-')
		return true;
	else return false;
}

void Matrix::Save(ofstream &os) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			os << i << "," << j << "=" << this->matrix[i][j] << endl;
		}
	}
}

void Matrix::Read(ifstream &is) {
	int aux, aux1;
	for (int i = 0; i < 9; i++) {
		is >> aux;
		is.ignore(INT16_MAX, ',');
		is >> aux1;
		is.ignore(INT16_MAX, '=');
		is >> this->matrix[aux][aux1];
	}
}

void Matrix::operator=(const Matrix newmat) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->matrix[i][j] = newmat.matrix[i][i];
		}
	}
}