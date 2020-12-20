// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Nome: Francisco Filipe
// AL 66613
// TIC

#include "pch.h"
#include <iostream>
#include "Menu.h"

using namespace std;

int main() {
	Menu menu = Menu();
	int option = 0;

	do {
		system("CLS");
		menu.View_B_Menu();
		menu.SetCondition(4);
		switch (option = menu.SelectOption()) {
		case 1:
			menu.PlayGame();
			break;
		case 2:
			system("CLS");
			menu.ViewHow2Play();
			system("PAUSE");
			break;
		case 3:
			system("CLS");
			menu.ViewRules();
			system("PAUSE");
			break;
		}
	} while (option != 4);

	system("CLS");
	cout << "Obrigado por jogar!";
	Sleep(2);
	return 0;
}
