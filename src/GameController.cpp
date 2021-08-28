#include"GameController.h"
#include<iostream>

Player GameController::currentPlayer = Player("player 1",'M');

GameController::GameController()
{

}
char GameController::getSelection()
{
    char option;
    cin>>option;
    return toupper(option);
}
string GameController::getString()
{
    string option;
    cin>>option;
    return option;
}
Player GameController::getPlayerCharacter()
{
    return currentPlayer;
}
void GameController::setPlayerCharacter(Player player)
{
    currentPlayer = player;
}
void GameController::MenuSelect()
{

}
