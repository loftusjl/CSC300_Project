#ifndef SELECTMENU_H
#define SELECTMENU_H
#include "Player.h"
#include <iostream>
using namespace std;
class SelectMenu
{
private:
	/* data */

public:
	SelectMenu(/* args */);
	~SelectMenu() {}
    static void selectMenu();
	static void GameMenu();
	static bool ExitGame();
	static Player CreateNewCharacter();
	void ContinueGame() const;
	static void setSelection(char);
    static void setGameMenu(char);
	void welcomeMsg() {cout<<"__________Welcome to IDLE RPG_________\n"<<endl;}
};

#endif