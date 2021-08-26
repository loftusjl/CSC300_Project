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
    switch(toupper(classID))
    {
    case 'M':
        this->setHitPoints(18*.40);
        this->setStrength(18*.25);
        this->setIntelligence(18*.65);
        this->setDexterity(18*.20);
        break;
    case 'W':
        this->setHitPoints(18*.65);
        this->setStrength(18*.55);
        this->setIntelligence(18*.25);
        this->setDexterity(18*.35);
        break;
    case 'S':
        this->setHitPoints(18*.45);
        this->setStrength(18*.30);
        this->setIntelligence(18*.50);
        this->setDexterity(18*.65);
        break;
    default:
        cout<<"\nError: No class selected.\n";
        break;
    }
}
