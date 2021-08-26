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
	void GameMenu();
	bool ExitGame();
	Player CreateNewCharacter() const;
	void ContinueGame() const;
	void setSelection(char);
    void setGameMenu(char);
	void welcomeMsg() {cout<<"__________Welcome to IDLE RPG_________\n"<<endl;}
};

#endif