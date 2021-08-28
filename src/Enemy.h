#ifndef ENEMY_H
#define ENEMY_H
#include"Entity.h"
#include<string>
using namespace std;

class Enemy: public Entity
{
public:
    Enemy() 
    {
        string types[] = {"Monster","Ghoul","Vampire","Rogue Knight","Darth Vader","Troll","Medusa"};
        RandRange typeRange(1,7);
        enemyType = types[typeRange.RandResult()];
    }
    string getEnemyType() {return enemyType;}
    void setEnemyType(string type) {enemyType = type;}

private:
    string enemyType;
};
#endif
