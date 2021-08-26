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
    Player theOpposer;
    Enemy theOpponent;
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

	bool Attack(int,int) const;
	bool Flee(int,int) const;
	void CastSpell(string);
    void welcomeMsg();

};
#endif