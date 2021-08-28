#ifndef ENTITY_H
#define ENTITY_H
#include<iostream>
#include "RandRange.h"
using namespace std;
class Entity
{
public:
    Entity();
    int getHealth() const;
    void setHealth(int);
    int getHitPoints() const;
    void setHitPoints(int);
    int getStrength() const;
    void setStrength(int);
    int getIntelligence();
    void setIntelligence(int);
    int getDexterity();
    void setDexterity(int);
    int getBaseAttackBonus() const;
    void setBaseAttackBonus(int);
    int getBaseEvasion() const;
    void setBaseEvasion(int);
    int getBaseDefenseBonus() const;
    void setBaseDefenseBonus(int);
    void displayStats();
    void updateHealth(int);

    int attackTotal();
    int defenseTotal();
    int evasionTotal();

private:
    int health;
    int hitPoints;
    int strength;
    int intelligence;
    int dexterity;
    int baseAttackBonus;
    int baseEvasion;
    int baseDefenseBonus;
    //Spell spell[];
    //Ability ability[];
};
#endif
