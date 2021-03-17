#pragma once

#include <iostream>
#include <string>
using namespace std;

class UserInput
{
	
private:
	string movementDirection = "";
	int playerAction = 0;
	char yesNo;

public:
	string getMovementDirection();

	void getPlayerAction();

	void getYesNo();

};

