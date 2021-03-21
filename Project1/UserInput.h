#pragma once

#include <iostream>
#include <string>
using namespace std;

class UserInput
{
	
private:
	string movementDirection = "";
	int playerAction = 0;
	char yesNo = 'a';

public:
	string getMovementDirection();

	int getPlayerAction();

	char getYesNo();

	int getPlayerCombatMove();

};

