#include "RandRange.cpp"

using namespace std;
#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
    Entity();
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

private:
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

Entity::Entity()
{
    RandRange rand = RandRange(1, 18);

    setHitPoints(rand.RandResult());
    setStrength(rand.RandResult());
    setIntelligence(rand.RandResult());
    setDexterity(rand.RandResult());
    setBaseAttackBonus(rand.RandResult());
    setBaseEvasion(rand.RandResult());
    setBaseDefenseBonus(rand.RandResult());
}
int Entity::getHitPoints() const
{
    return hitPoints;
}
int Entity::getStrength() const
{
    return strength;
}
int Entity::getIntelligence()
{
    return intelligence;
}
int Entity::getDexterity()
{
    return dexterity;
}

int Entity::getBaseAttackBonus() const
{
    return baseAttackBonus;
}
int Entity::getBaseEvasion() const
{
    return baseEvasion;
}
int Entity::getBaseDefenseBonus() const
{
    return baseDefenseBonus;
}
void Entity::setBaseAttackBonus(int attack)
{
    baseAttackBonus = attack;
}
void Entity::setHitPoints(int hit)
{
    hitPoints = hit;
}
void Entity::setStrength(int str)
{
    strength = str;
}
void Entity::setIntelligence(int intel)
{
    intelligence = intel;
}
void Entity::setDexterity(int dex)
{
    dexterity = dex;
}
void Entity::setBaseEvasion(int evasion)
{
    baseEvasion = evasion;
}
void Entity::setBaseDefenseBonus(int defense)
{
    baseDefenseBonus = defense;
}
