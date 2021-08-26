#include <iostream>
#include"GameController.h"
#include"SelectMenu.h"
#include"TravelScreen.h"
#include"CombatScreen.h"
#include"Entity.h"
#include"Enemy.h"
#include"Player.h"


using namespace std;

int main()
{
    GameController controller;
    SelectMenu mainMenu;
    mainMenu.setSelection(controller.getSelection());
}