#include "UserInput.h"
using namespace std;

string UserInput::getMovementDirection()
{
	bool bValidInput = false;
	std::cout << "Please enter the direction you want to move in: ";
	do 
	{
		cin >> movementDirection;
		if (movementDirection == "North" || movementDirection == "South" || movementDirection == "East" || movementDirection == "West")
		{
			bValidInput = true;
			if (movementDirection == "North")
			{
				return "North";
			}
			else if (movementDirection == "South")
			{
				return "South";
			}
			else if (movementDirection == "East")
			{
				return "East";
			}
			else if (movementDirection == "West")
			{
				return "West";
			}
		}
		else
		{
			std::cout << "Please enter a valid direction: ";
		}
	} while (!bValidInput);
	
}

void UserInput::getPlayerAction()
{
	bool bValidInput = false;
	std::cout << "Please enter the action you wish to preform: ";
	do 
	{
		cin >> playerAction;
		if (playerAction == 1 || playerAction == 2 || playerAction == 3)
		{
			bValidInput = true;
		}
		else
		{
			std::cout << "Please enter a valid task to preform: ";
		}
	} while (!bValidInput);
}

void UserInput::getYesNo()
{
	bool bValidInput = false;
	std::cout << "Y or N: ";
	do
	{
		cin >> yesNo;
		if (yesNo == 'Y' || yesNo == 'N')
		{
			bValidInput = true;
		}
		else
		{
			std::cout << "Please select either Y or N: ";
		}
	} while (!bValidInput);
}
