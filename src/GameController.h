#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include"Player.h"
using namespace std;

class GameController
{
private:
    static Player currentPlayer; 
public:
    GameController(/* Args */);
    ~GameController() {}
    static char getSelection();
    static string getString();
    static Player getPlayerCharacter();
    static void setPlayerCharacter(Player);
    static void updatePlayerCharacter(string,char);

    void MenuSelect();
};
#endif