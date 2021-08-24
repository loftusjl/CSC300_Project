#include "Entity.cpp"
#include <iostream>
using namespace std;

int main()
{

    Entity player;

    std::cout << "Starting Stats:\n HP: " << player.getHitPoints() << "\nBAB: " << player.getBaseAttackBonus() << std::endl;
    cout << endl;
}