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
	setPlayer(GameController::getPlayerCharacter());
	setEnemy(randEnemy);
	welcomeMsg();
	combatMenu();
}
void CombatScreen::displayCombatScreen()
{
	cout<<right;
	cout<<setw(18)<<player.getPlayerName()<<"__VS__"<<enemy.getEnemyType()<<endl;
	int opposerStats[] = {player.getHealth(),player.getHitPoints(),player.getStrength(),player.getIntelligence(),player.getDexterity(),player.getBaseAttackBonus(),player.getBaseDefenseBonus(),player.getBaseEvasion()};
	int opponentStats[] = {enemy.getHealth(),enemy.getHitPoints(),enemy.getStrength(),enemy.getIntelligence(),enemy.getDexterity(),enemy.getBaseAttackBonus(),enemy.getBaseDefenseBonus(),enemy.getBaseEvasion()};
	string entityAtr[] = {"Health","Damage","Strength","Intelligence","Dexterity","Attack Bonus","Defense Bonus","Evasion"};
	for(int i = 0;i<8;i++)
	{
		cout<<right;
		cout<<setw(13)<<entityAtr[i]<<": "<<setw(3)<<opposerStats[i]<<setw(8)<<"__VS__"<<setw(4)<<opponentStats[i]<<endl;
	}
}
Enemy CombatScreen::getEnemy()
{
	return enemy;
}
Player CombatScreen::getPlayer()
{
	return player;
}
void CombatScreen::setPlayer(Player player)
{
	this->player = player;
}
void CombatScreen::setEnemy(Enemy enemy)
{
	this->enemy = enemy;
}

bool CombatScreen::Attack(int playerHits,int enemyHits)
{
	bool didWin;
	if(playerHits >= enemyHits)
	{
		didWin = true;
	}
	else 
		didWin = false;
	player.updateHealth(enemyHits);
	enemy.updateHealth(playerHits);
	return didWin;
}
bool CombatScreen::Flee(int flee,int attack)
{
	bool didFlee;
	if(flee > attack)
	{
		didFlee = true;
	}
	else
	{
		didFlee = false;
	}
	return didFlee;
}

void CombatScreen::combatMenu() 
{
	for(int i = 0;i<3;i++)
		cout<<"*"<<setw(26)<<"*\n";
	cout<<enemy.getEnemyType()<<" has entered the Arena."<<endl;

	do
	{
		displayCombatScreen();
		displayCombatOptions();
		fightResult(playerAction(),enemyAction());
	} 
	while (player.getHealth() > 0 && enemy.getHealth() > 0);

	if(enemy.getHealth() <= 0)
	{
		cout<<player.getPlayerName()<<" has defeated "<<enemy.getEnemyType()<<endl;
		SelectMenu::GameMenu();
		SelectMenu::setGameMenu(GameController::getSelection());
	}
	else if(player.getHealth() <= 0)
	{
		cout<<player.getPlayerName()<<" has been defeated."<<endl;
		SelectMenu::selectMenu();
		SelectMenu::setSelection(GameController::getSelection());
	}
}
void CombatScreen::displayCombatOptions()
{
	cout<<"A for Attack\n"
	<<"D for Defend\n"
	<<"E for Evade\n";
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

char CombatScreen::playerAction()
{
	char playerChoice = GameController::getSelection();
	return playerChoice;
}
char CombatScreen::enemyAction()
{
	RandRange choiceRange(1,3);
	char choices[] = {'A','D','E'};
	char enemyChoice = choices[choiceRange.RandResult()-1];
	return enemyChoice;
}


bool CombatScreen::fightResult(char playerAction, char enemyAction)
{
	bool won;
	switch (playerAction)
	{
	case 'A':
		cout<<player.getPlayerName()<<" attacks! ";
		switch(enemyAction)
		{
			case 'A':
				cout<<enemy.getEnemyType()<<" attacks!"<<endl;
				if(!Attack(player.attackTotal(),enemy.attackTotal()))
				{
					cout<<player.getPlayerName()<<" lost this round.\n";
				}
				else 
					cout<<player.getPlayerName()<<" won this round.\n";
				break;
			case 'D':
				cout<<enemy.getEnemyType()<<" defends!"<<endl;
				if(enemy.defenseTotal() > player.attackTotal())
				{
					cout<<"Enemy defense wins, you've been countered\n";
					Attack(0,enemy.getHitPoints());
				}
				else
				{
					cout<<"You broke through the Enemy defense\n";
					Attack(player.getHitPoints(),0);
				}
				break;
			case 'E':
				cout<<enemy.getEnemyType()<<" evades!"<<endl;
				if(Flee(enemy.getBaseEvasion(),player.getHitPoints()))
				{
					cout<<"Enemy evaded successfully\n";
					SelectMenu::GameMenu();
					SelectMenu::setGameMenu(GameController::getSelection());
				}
				else
				{
					cout<<"Enemy failed to evade\n";
					enemy.updateHealth(player.getHitPoints());
				}
				break;
			default:
				break;
		}
		break;
	case 'D':
		cout<<player.getPlayerName()<<" defends! ";
		switch(enemyAction)
		{
			case 'A':
				cout<<enemy.getEnemyType()<<" attacks!"<<endl;
				if(player.defenseTotal() > enemy.attackTotal())
				{
					cout<<"Player defense wins, you preformed counter.\n";
					Attack(player.getHitPoints(),0);
					
				}
				else
				{
					cout<<"Enemy broke through your defense.\n";
					Attack(0,enemy.getHitPoints());
				}
				break;
			case 'D':
				cout<<enemy.getEnemyType()<<" defends!"<<endl;
				cout<<"Stalemate.\n";
				break;
			case 'E':
				cout<<enemy.getEnemyType()<<" evades!"<<endl;
				SelectMenu::GameMenu();
				SelectMenu::setGameMenu(GameController::getSelection());
				break;
			default:
				break;
		}
		break;
	case 'E':
		cout<<player.getPlayerName()<<" evades!"<<endl;
		switch(enemyAction)
		{
			case 'A':
				cout<<enemy.getEnemyType()<<" attacks!"<<endl;
				if(Flee(player.getBaseEvasion(),enemy.getHitPoints()))
				{
					cout<<player.getPlayerName()<<" evaded successfully\n";
					SelectMenu::GameMenu();
					SelectMenu::setGameMenu(GameController::getSelection());
				}
				else
				{
					cout<<player.getPlayerName()<<" failed to evade\n";
					player.updateHealth(enemy.getHitPoints());
				}
				break;
			case 'D':
				cout<<enemy.getEnemyType()<<" defends!"<<endl;
				SelectMenu::GameMenu();
				SelectMenu::setGameMenu(GameController::getSelection());
				break;
			case 'E':
				cout<<enemy.getEnemyType()<<" evades!"<<endl;
				SelectMenu::GameMenu();
				SelectMenu::setGameMenu(GameController::getSelection());
				break;
			default:
				break;
		}
		break;
	default:
		cout<<"Error: invalid selection"<<endl;
		break;
	}
	return won;
}