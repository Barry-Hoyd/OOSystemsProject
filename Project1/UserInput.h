#pragma once

#include <iostream>
#include <string>
using namespace std;

class UserInput
{
	
private:
	string movementDirection = "";
	string itemToUse = "";
	int playerAction = 0;
	int playerActionCombat = 0;
	char yesNo = 'a';
public:
	string getMovementDirection();

	int getPlayerAction();

	char getYesNo();

	int getPlayerCombatMove();

	string getInventoryControl();

	int getPlayerRoomAction();
};

