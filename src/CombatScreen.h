#ifndef COMBATSCREEN_H
#define COMBATSCREEN_H
#include"Entity.h"
#include"Player.h"
#include "Enemy.h"
#include<string>
using namespace std;

class CombatScreen
{
private:
    static Player player;
    static Enemy enemy;
public:
	CombatScreen();
	~CombatScreen() {}
    Enemy getEnemy();
    Player getPlayer();
    void setPlayer(Player);
    void setEnemy(Enemy);

    void combatMenu();
	void displayCombatScreen();
    void displayCombatOptions();

	int getEntityTurn() const;
	void setEntityTurn();

	bool Attack(int,int);
	bool Flee(int,int);
	void CastSpell();
    void welcomeMsg();

    char playerAction();
    char enemyAction();
    bool fightResult(char,char);
    


};
#endif