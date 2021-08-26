#include"Entity.h"
Entity::Entity()
{
    RandRange rand = RandRange(1, 18);
    setHealth(100);
    setHitPoints(rand.RandResult());
    setStrength(rand.RandResult());
    setIntelligence(rand.RandResult());
    setDexterity(rand.RandResult());
    setBaseAttackBonus(rand.RandResult());
    setBaseEvasion(rand.RandResult());
    setBaseDefenseBonus(rand.RandResult());
}
int Entity::getHealth() const
{
    return health;
}
void Entity::setHealth(int newHealth)
{
    health = newHealth;
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
void Entity::displayStats()
{
    cout<<"\nHit Points: "<<getHitPoints()
    <<"\nStrength: "<<getStrength()
    <<"\nIntelligence: "<<getIntelligence()
    <<"\nDexterity: "<<getDexterity()
    <<"\nBase Attack Bonus: "<<getBaseAttackBonus()
    <<"\nBase Defense Bonus: "<<getBaseDefenseBonus()
    <<"\nBase Evasion: "<<getBaseEvasion()<<endl;
}