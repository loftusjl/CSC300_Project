#include "Player.cpp"
#include <iostream>

using namespace std;
class SelectMenu
{
private:
	/* data */

public:
	SelectMenu(/* args */) {}
	~SelectMenu() {}
	void DisplaySelectMenu();
	bool ExitGame();
};

void SelectMenu::DisplaySelectMenu()
{
	std::cout << "Select Menu..." << std::endl;
};

bool SelectMenu::ExitGame()
{
	std::cout << "Are you sure?" << std::endl; //! get user confirmation input
	return true;
};