#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include "List.hpp"

class Menu
{
private:
	int menuChoice;
	List<Data> masterList;
	std::ifstream classList;
	std::fstream master;
	std::ofstream absenceReport1;
	std::ofstream absenceReport2;

public:
	Menu(int _menuChoice = -1);

	void getUserChoice();

	int getMenuChoice();
	void printOptions();
	void runSelectedChoice();
};

#endif