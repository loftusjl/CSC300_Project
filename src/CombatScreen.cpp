#include"CombatScreen.h"
#include"GameController.h"
#include <iomanip> //set width
using namespace std;

CombatScreen::CombatScreen()
{
	Enemy randEnemy;
	setOpposer(GameController::getPlayerCharacter());
	setOpponent(randEnemy);
	welcomeMsg();
	combatMenu();
}
void CombatScreen::DisplayCombatScreen()
{
	cout<<"Opposer_______VS______Opponent"<<endl;
	cout<<"____________Damage____________\n"
	<<theOpposer.getHitPoints()<<setw(28)<<theOpponent.getHitPoints()<<endl;
	cout<<"___________Strength___________\n"
	<<theOpposer.getStrength()<<setw(28)<<theOpponent.getStrength()<<endl;
	cout<<"_________Intelligence_________\n"
	<<theOpposer.getIntelligence()<<setw(28)<<theOpponent.getIntelligence()<<endl;
	cout<<"__________Dexterity___________\n"
	<<theOpposer.getDexterity()<<setw(28)<<theOpponent.getDexterity()<<endl;

}
Enemy CombatScreen::getEnemy()
{
	Enemy enemy;
	return enemy;
}
Player CombatScreen::getOpposer()
{
	return theOpposer;
}
void CombatScreen::setOpposer(Player opposer)
{
	theOpposer = opposer;
}
Enemy CombatScreen::getOpponent()
{
	return theOpponent;
}
void CombatScreen::setOpponent(Enemy opponent)
{
	theOpponent = opponent;
}

// bool CombatScreen::Attack(int opposerHits,int opponentHits) const
// {
// 	bool didWin;
// 	theOpposer.setHealth(theOpposer.getHealth() - opponentHits);

// 	return didWin;
// }
// bool CombatScreen::Flee(int,int) const
// {

// }

void CombatScreen::combatMenu() 
{
	for(int i =0;i<3;i++)
		cout<<"*"<<setw(26)<<"*\n";

	DisplayCombatScreen();
	cout<<"A for Attack\n"
	<<"C for Cast Spell\n"
	<<"F for Flee\n";
	char userChoice;
	while(theOpponent.getHealth() > 0 && theOpposer.getHealth() > 0 || userChoice != 'F')
	{
		userChoice = GameController::getSelection();
		switch (userChoice)
		{
		case 'A':
			cout<<"*BooooM* *POOWwww*";
			break;
		case 'C':
			cout<<"Expecto Pa Tronium";
			break;
		case 'F':
			cout<<"AHHH im out!";
			break;
		default:
			cout<<"Invalid: Selction";
			break;
		}
	}
}
void CombatScreen::CastSpell(string) 
{

}
void CombatScreen::welcomeMsg()
{
	cout<<"\n_____Entering_Combat_____"<<endl;
}