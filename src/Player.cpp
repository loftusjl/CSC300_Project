#include<iostream>
#include<string>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
    Player(string name);
    string getPlayerName() const;
    void setPlayerName(string);
private:
    string playerName;
};
#endif

Player::Player(string name)
{
    setPlayerName(name);
}
string Player::getPlayerName() const
{
    return playerName;
}
void Player::setPlayerName(string name)
{
    playerName = name;
}