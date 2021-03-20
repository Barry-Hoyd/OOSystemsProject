#include "UserInput.h"
using namespace std;

string UserInput::getMovementDirection()
{
	bool bValidInput = false;
	std::cout << "Please enter the direction you want to move in: ";
	do 
	{
		cin >> movementDirection;
		if (movementDirection == "North" || movementDirection == "South")
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
		}
		else
		{
			std::cout << "Please enter a valid direction: ";
		}
	} while (!bValidInput);
	
}

int UserInput::getPlayerAction()
{
	bool bValidInput = false;
	do 
	{
		cin >> playerAction;
		if (playerAction == 1 || playerAction == 2 || playerAction == 3 || playerAction ==4)
		{
			if (playerAction == 1)
			{
				return 1;
			}
			else if (playerAction == 2)
			{
				return 2;
			}
			else if (playerAction == 3)
			{
				return 3;
			}
			else if (playerAction == 4)
			{
				return 4;
			}
		}
		else
		{
			std::cout << "Please enter a valid task to preform: ";
		}
	} while (!bValidInput);
}

char UserInput::getYesNo()
{
	bool bValidInput = false;
	std::cout << "Would you like to pick it up? Y or N?: ";
	do
	{
		cin >> yesNo;
		if (yesNo == 'Y' || yesNo == 'N')
		{
			bValidInput = true;
			if (yesNo == 'Y')
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		else
		{
			std::cout << "Please select either Y or N: ";
		}
	} while (!bValidInput);
}
