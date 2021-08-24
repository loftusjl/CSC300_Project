using namespace std;
#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
    Entity();
    int getHitPoints() const;
    void setHitPoints(int);
    int getBaseAttackBonus() const;
    void setBaseAttackBonus(int);
    int getBaseEvasion() const;
    void setBaseEvasion(int);
    int getBaseDefenseEvasion() const;
    void setBaseDefenseEvasion(int);
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
    int hitPoints = 0;
    int strength = 0;
    int intelligence = 0;
    int dexterity = 0;
    int baseAttackBonus = 0;
    int baseEvasion = 0;
    int baseDefenseBonus = 0;
}
int Entity::getHitPoints() const
{
    return hitPoints;
}
int Entity::getBaseAttackBonus() const
{
    return baseAttackBonus;
}
int Entity::getBaseEvasion() const
{
    return baseEvasion;
}
int Entity::getBaseDefenseEvasion() const
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
void Entity::setBaseEvasion(int evasion)
{
    baseEvasion = evasion;
}
void Entity::setBaseDefenseEvasion(int defense)
{
    baseDefenseBonus = defense;
}
