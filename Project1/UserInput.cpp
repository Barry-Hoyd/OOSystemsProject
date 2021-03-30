#include "UserInput.h"
#include "RoomGenerator.h"
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

int UserInput::getPlayerCombatMove()
{
	bool bValidInput = false;
	playerActionCombat = 0;
	std::cout << "It is your turn. \n";
	std::cout << "[1] Attack \n";
	std::cout << "[2] Defend \n";
	std::cout << "[3] Use Item \n";
	std::cout << "Action Choice: ";
	do
	{
		cin >> playerActionCombat;
		if (playerActionCombat == 1 || playerActionCombat == 2 || playerActionCombat == 3)
		{
			bValidInput = true;
			if (playerActionCombat == 1)
			{
				cin.clear();
				return 1;
			}
			else if (playerActionCombat == 2)
			{
				cin.clear();
				return 2;
			}
			else if (playerActionCombat == 3)
			{
				cin.clear();
				return 3;
			}
		}
		else
		{
			std::cout << "Please enter a valid task to preform: ";
		}
		throw (playerActionCombat);
	} while (!bValidInput);
}

string UserInput::getInventoryControl()
{
	bool bValidInput = false;
	itemToUse = "";
	std::cout << "Please select the item you want to use: ";
	do
	{
		cin >> itemToUse;
		if (itemToUse == "Health" || itemToUse == "Bomb")
		{
			bValidInput = true;
			if (itemToUse == "Health")
			{
				return "Health";
			}
			else if (itemToUse == "Bomb")
			{
				return "Bomb";
			}
			
		}
		else
		{
			std::cout << "Only bombs and health potions can be used in combat! \n";
			return "None";
		}
	} while (!bValidInput);
}

int UserInput::getPlayerRoomAction()
{
	bool bValidInput = false;
	playerActionCombat = 0;
	std::cout << "[1] Move \n";
	std::cout << "[2] Pray \n";
	std::cout << "[3] Inventory \n";
	std::cout << "Action Choice: ";

	do
	{
		cin >> playerActionCombat;
		if (playerActionCombat == 1 || playerActionCombat == 2 || playerActionCombat == 3)
		{
			bValidInput = true;
			if (playerActionCombat == 1)
			{
				cin.clear();
				return 1;
			}
			else if (playerActionCombat == 2)
			{
				cin.clear();
				return 2;
			}
			else if (playerActionCombat == 3)
			{
				cin.clear();
				return 3;
			}
		}
		else
		{
			std::cout << "Please enter a valid task to preform: ";
		}
		throw (playerActionCombat);
	} while (!bValidInput);
}
