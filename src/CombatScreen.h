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
    void combatMenu();
	void DisplayCombatScreen();

	int getEntityTurn() const;
	void setEntityTurn();

	Enemy getEnemy();

    Player getOpposer();
    void setOpposer(Player);
    Enemy getOpponent();
    void setOpponent(Enemy);

	bool Attack(int,int);
	bool Flee(int,int);
	void CastSpell();
    void welcomeMsg();

    void displayVSscreen();
    void attackStatsDisplay();

};
#endif