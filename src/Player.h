#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
using namespace std;

class Player: public Entity
{
public:
    Player();
    Player(string,char);
    ~Player() {}
    string getPlayerName() const;
    void setPlayerName(string);
    string getPlayerClass() const;
    void setPlayerClass(char);
    void displayStats();
    void initClassStats(char);
    friend ostream& operator<<(ostream&,const Player&);

private:
    string playerName;
    char playerClass;
    
};
#endif