#include "PlayerMovement.h"
#include <iostream>

//RoomGenerator room5(1, 1, Monster, Cyclops, true, false, false, false, false, false, "Pee Pee Poo Poo.");

PlayerMovement::PlayerMovement()
{
	
}

int PlayerMovement::getPlayerLoaction()
{
    return playerLoaction;
}

void PlayerMovement::setPlayerLoaction(int location)
{
    playerLoaction = location;
}

void PlayerMovement::InitaliseMap()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Map[i][j] = 0;
		}
	}
}

void PlayerMovement::DisplayMap()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << Map[i][j];
		}
		std::cout << "\n";
	}
}

void PlayerMovement::SpawnPlayer()
{
	Map[2][1] = 1;
	
	std::cout << "You awaken in a darken room. You have no idea how you got here. "<< "\n" << "You know that adventuring through the rooms will be the best chance of escape." << "\n";
	//room7.DisplayCurrentRoom(2,1);
}

void PlayerMovement::MovePlayer()
{
	int x = 0;
	int y = 0;
	bool bAlreadyMoved = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] == 1)
			{
				x = i;
				y = j;
				if (!bAlreadyMoved)
				{
					std::string input = userInput.getMovementDirection();
					if (input == "North")
					{
						MoveNorth(x, y);
						bAlreadyMoved = true;
						
					}
					else if (input == "South")
					{
						MoveSouth(x, y);
						bAlreadyMoved = true;
						
					}
					else if (input == "East")
					{
						MoveEast(x, y);
						bAlreadyMoved = true;
						
					}
					else if (input == "West")
					{
						MoveWest(x, y);
						bAlreadyMoved = true;	
					}
				}
			}
		}
	}
}

void PlayerMovement::MoveNorth(int x, int y)
{
	if (x != 0)
	{
		if (x == 1 && y == 1 && playerMonk.getKey() == false)
		{
			std::cout << "You need to find a key to open the door." << "\n";
		}
		else
		{
			Map[x - 1][y] = 1;
			Map[x][y] = 0;
			//roomGenerator.DisplayCurrentRoom(x-1, y);
			if (x - 1 == 1 && y == 1)
			{
				//room5.getDescription();
				std::cout << "\n";
			}
		}
	}
	else
	{
		std::cout << "You cannot go North here." << "\n";
	}
}

void PlayerMovement::MoveSouth(int x, int y)
{
	if (x != 2)
	{
		Map[x + 1][y] = 1;
		Map[x][y] = 0;
		//roomGenerator.DisplayCurrentRoom(x + 1, y);
	}
	else
	{
		std::cout << "You cannot go South here." << "\n";
	}
}

void PlayerMovement::MoveEast(int x, int y)
{
	if (y == 2 || x == 1 && y == 1 || x == 0 && y == 1 || x ==1 && y == 0 || x == 0 && y == 0)
	{
		std::cout << "You cannot go East here." << "\n";	
	}
	else
	{
		Map[x][y + 1] = 1;
		Map[x][y] = 0;
		//roomGenerator.DisplayCurrentRoom(x, y+1);
	}
}

void PlayerMovement::MoveWest(int x, int y)
{
	if (y == 0 || x == 1 && y == 1 || x == 0 && y == 2)
	{
		std::cout << "You cannot go West here." << "\n";
	}
	else
	{
		Map[x][y - 1] = 1;
		Map[x][y] = 0;
		//roomGenerator.DisplayCurrentRoom(x, y - 1);
	}
}


