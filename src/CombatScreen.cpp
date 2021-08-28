#include"CombatScreen.h"
#include"GameController.h"
#include"SelectMenu.h"
#include <iomanip> //set width
using namespace std;

Player CombatScreen::player;
Enemy CombatScreen::enemy;

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
	cout<<right;
	cout<<setw(18)<<player.getPlayerName()<<"__VS__"<<enemy.getEnemyType()<<endl;
	displayVSscreen();
	
}
Enemy CombatScreen::getEnemy()
{
	Enemy enemy;
	return enemy;
}
Player CombatScreen::getOpposer()
{
	return player;
}
void CombatScreen::setOpposer(Player player)
{
	this->player = player;
}
Enemy CombatScreen::getOpponent()
{
	return enemy;
}
void CombatScreen::setOpponent(Enemy enemy)
{
	this->enemy = enemy;
}

bool CombatScreen::Attack(int playerHits,int enemyHits)
{
	bool didWin;
	if(player.attackTotal() > enemy.defenseTotal())
	{
		cout<<"Clean strike"<<endl;
		enemy.updateHealth(playerHits);
		didWin  = true;
	}
	else if(player.attackTotal() == enemy.defenseTotal())
	{
		cout<<"Evenly matched, you both took damage"<<endl;
		enemy.updateHealth(playerHits);
		player.updateHealth(enemyHits);
		if(playerHits > enemyHits)
			didWin = true;
	}
	else
	{
		cout<<"The Opponent's defense is too stronger, you have been countered\n";
		player.updateHealth(enemyHits);
		didWin = false;
	}

	return didWin;
}
bool CombatScreen::Flee(int playerHits,int enemyHits)
{
	bool didFlee;
	if(player.evasionTotal() > enemy.attackTotal())
	{
		cout<<"Flee Succesful."<<endl;
		didFlee = true;
	} 
	else if (player.evasionTotal() == enemy.attackTotal())
	{
		cout<<"Flee was succesful but you got knicked."<<endl;
		player.updateHealth(enemyHits/2);
		didFlee = true;
	}
	else 
	{
		cout<<"Flee was unsuccesful, you took damage."<<endl;
		if(player.defenseTotal() >= enemy.attackTotal())
		{
			cout<<"But your defense saved you."<<endl;
			enemy.updateHealth(playerHits);
			player.updateHealth(enemyHits);
		}
		player.updateHealth(enemyHits);
		didFlee = false;
	}

	return didFlee;

}

void CombatScreen::combatMenu() 
{
	for(int i = 0;i<3;i++)
		cout<<"*"<<setw(26)<<"*\n";

	DisplayCombatScreen();
	cout<<"A for Attack\n"
	<<"C for Cast Spell\n"
	<<"F for Flee\n";
	char userChoice;
	while(enemy.getHealth() > 0 && player.getHealth() > 0)
	{
		userChoice = GameController::getSelection();
		switch (userChoice)
		{
		case 'A':
			cout<<"*BooooM* *POOWwww*"<<endl;
			if(Attack(player.getHitPoints(),enemy.getHitPoints()))
			{
				cout<<player.getPlayerName()<<" Wins this round"<<endl;
			}
			else{
				cout<<"The "<<enemy.getEnemyType()<<" Wins this round"<<endl;
			}
			break;
		case 'C':
			CastSpell();
			break;
		case 'F':
			if(Flee(player.getHitPoints(),enemy.getHitPoints()))
			{
				SelectMenu::GameMenu();
				SelectMenu::setGameMenu(GameController::getSelection());
			}
			break;
		default:
			cout<<"Invalid: Selction"<<endl;
			break;
		}
		displayVSscreen();
	}
}
void CombatScreen::CastSpell() 
{
	if(player.getPlayerClass() == "Magician")
	{
		string spell;
		cout<<"Cast Spell: ";
		cin >> spell;
		cout<<spell<<" effects... \n";
	}
	else
	{
		cout<<"You have no spells to cast.\n";
	}
}
void CombatScreen::welcomeMsg()
{
	cout<<"\n_____Entering_Combat_____"<<endl;
}
void CombatScreen::displayVSscreen()
{
	int opposerStats[] = {player.getHealth(),player.getHitPoints(),player.getStrength(),player.getIntelligence(),player.getDexterity(),player.getBaseAttackBonus(),player.getBaseDefenseBonus(),player.getBaseEvasion()};
	int opponentStats[] = {enemy.getHealth(),enemy.getHitPoints(),enemy.getStrength(),enemy.getIntelligence(),enemy.getDexterity(),enemy.getBaseAttackBonus(),enemy.getBaseDefenseBonus(),enemy.getBaseEvasion()};
	string entityAtr[] = {"Health","Damage","Strength","Intelligence","Dexterity","Attack Bonus","Defense Bonus","Evasion"};
	for(int i = 0;i<8;i++)
	{
		cout<<right;
		cout<<setw(13)<<entityAtr[i]<<": "<<setw(3)<<opposerStats[i]<<setw(8)<<"__VS__"<<setw(4)<<opponentStats[i]<<endl;
	}
		
	
}
void CombatScreen::attackStatsDisplay()
{
	int opposerStats[] = {player.getHitPoints(),enemy.getHitPoints(),player.getHealth()};
	int opponentStats[] = {enemy.getHitPoints(),player.getHitPoints(),enemy.getHealth()};
	string stats[] = {"Damage Given: ","Damage Recieved: ","Health: "};
	for(int i = 0;i<3;i++)
		cout<<stats[i]<<opposerStats[i]<<"____"<<opponentStats[i]<<endl;
	
}