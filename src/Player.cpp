#include"Player.h"

Player::Player()
{

}
Player::Player(string name,char classID)
{
    setPlayerName(name);
    setPlayerClass(classID);
}
string Player::getPlayerName() const
{
    return playerName;
}
void Player::setPlayerName(string name)
{
    playerName = name;
}
void Player::setPlayerClass(char classID)
{
    playerClass = toupper(classID);
    initClassStats(classID);
}
string Player::getPlayerClass() const
{
    string className;
    switch (toupper(playerClass))
    {
    case 'M':
        className = "Magician";
        break;
    case 'W':
        className = "Warrior";
        break;
    case 'S':
        className = "Scoutsman";
        break;
    default:
        break;
    }
    return className;
}
ostream& operator<<(ostream& out,const Player& player)
{
    out<<player.playerName;
    return out;
}
void Player::displayStats()
{
    cout<<getPlayerName()<<"\n"
    <<getPlayerClass()<<" class\n";
    this->Entity::displayStats();
}
void Player::initClassStats(char classID)
{
    const int max = 18;
    switch(toupper(classID))
    {
    case 'M':
        this->setHitPoints(max * .25);
        this->setStrength(max * .25);
        this->setIntelligence(max * .75);
        this->setDexterity(max * .50);
        this->setBaseAttackBonus(max * .25);
        this->setBaseDefenseBonus(max * .75);
        this->setBaseEvasion(max * .75);
        break;
    case 'W':
        this->setHitPoints(max * .75);
        this->setStrength(max * .50);
        this->setIntelligence(max * .25);
        this->setDexterity(max * .50);
        this->setBaseAttackBonus(max * .50);
        this->setBaseDefenseBonus(max * .50);
        this->setBaseEvasion(max * .25);
        break;
    case 'S':
        this->setHitPoints(max * .50);
        this->setStrength(max * .25);
        this->setIntelligence(max * .75);
        this->setDexterity(max *.75);
        this->setBaseAttackBonus(max * .75);
        this->setBaseDefenseBonus(max * .75);
        this->setBaseEvasion(max * .75);
        break;
    default:
        cout<<"\nError: No class selected.\n";
        break;
    }
}
