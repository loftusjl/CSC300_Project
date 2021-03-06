#include"SelectMenu.h"
#include"GameController.h"
#include"CombatScreen.h"


SelectMenu::SelectMenu() //Menu when first starting game
{
	welcomeMsg();

}
void SelectMenu::selectMenu()
{
	cout<<"N for New Game"<<endl;
	cout<<"C for Continue Game"<<endl;
	cout<<"E for Exit Game"<<endl;
	cout<<"\nType one of the following options: ";
}

void SelectMenu::GameMenu() //Game Menu which shows after character creation or shows first when starting game up
{
	cout<<"\nSelect one of the following options\n";
	cout << "C for Combat\n";
	cout << "T for Travel\n";
	cout << "A for Autopilot\n";
	cout << "M for Main Menu\n";
}

bool SelectMenu::ExitGame()
{
	bool finalAnswer = false;
	std::cout << "Are you sure? y/n" << std::endl; //! get user confirmation input
	char choice = GameController::getSelection();
	if(choice == 'Y'||'y')
		finalAnswer = true;

	return finalAnswer;
}

Player SelectMenu::CreateNewCharacter() //creates a character and passes to game controller as the currentPlayer
{
	Player player;
	cout<<"__________Create Your Character__________\n"
	<<"Enter Character's name: ";
	string name = GameController::getString();
	cout<<"Choose "<<name<<"'s Class"<<
	"\n____Magaician____\n";
	player.setPlayerClass('M');
	player.displayStats();
	cout<<"____Warrior____\n";
	player.setPlayerClass('W');
	player.displayStats();
	cout<<"____Scoutsman____\n";
	player.setPlayerClass('S');
	player.displayStats();
	cout<<"\nM for Magician\nW for Warrior\nS for Scoutsman: ";
	char playerClass = GameController::getSelection();
	player.setPlayerName(name);
	player.setPlayerClass(playerClass);
	GameController::setPlayerCharacter(player);
	cout<<"* * * * Welcome "<<name<<" The "<<player.getPlayerClass()<<" * * * * "<<endl;

	return player;
}

void SelectMenu::setSelection(char userChoice) //Sets the user selection for the SelectMenu()
{
	switch(userChoice)
	{
	case 'N':
		GameController::setPlayerCharacter(CreateNewCharacter());
		GameMenu();
		setGameMenu(GameController::getSelection());
		break;
	case 'C':
		cout<<"Continue Game"<<endl;
		GameMenu();
		setGameMenu(GameController::getSelection());
		break;
	case 'E':
		cout<<"Exit Game"<<endl;
		if(ExitGame())
		{
			return;
		}
		else 
		{
			selectMenu();
			setSelection(GameController::getSelection());
		}
		break;
	default:
		cout<<"Error: invalid choice"<<endl;
		break;
	}
}

void SelectMenu::setGameMenu(char userChoice) //sets the user selection for the GameMenu()
{
	switch(userChoice)
	{
	case 'C':
		CombatScreen();
		break;
	case 'T':
		cout<<"Travel Screen"<<endl;
		break;
	case 'A':
		cout<<"Auto Pilot Engage"<<endl;
		break;
	case 'M':
		cout<<"Main Menu"<<endl;
		selectMenu();
		setSelection(GameController::getSelection());
		break;
	default:
		cout<<"Error: invalid choice"<<endl;
		break;
	}
}