#include "Entity.cpp"
#include<string>
using namespace std;

#ifndef ENEMY_H
#define ENEMY_H
class Enemy: public Entity
{
public:
    Enemy();
    Enemy(string);
    string getEnemyName() const;
    void setEnemyName(string);
private:
    string enemyName;
};
#endif

Enemy::Enemy()
{
    enemyName = "";
}
Enemy::Enemy(string name)
{
    setEnemyName(name);
}
string Enemy::getEnemyName() const
{
    return enemyName;
}
void Enemy::setEnemyName(string name)
{
    enemyName = name;
}