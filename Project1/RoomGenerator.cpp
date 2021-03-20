#include "RoomGenerator.h"
PlayerMonk playerMonk;
UserInput userInput;

void RoomGenerator::GenerateMap(int numberOfRooms)
{
	srand((int)time(0)); //Used to randomise the attack pattern each time
	Map = new RoomGenerator[numberOfRooms];
	for (int x = 0; x < numberOfRooms; x++)
	{
		if (x == 0)
		{
			SpawnRoom spawnRoom(Spawn);
			Map[0] = spawnRoom;
		}
		else if (x == numberOfRooms /2)
		{
			KeyRoom keyRoom(x, Key);
			Map[x] = keyRoom;
		}
		else if (x != numberOfRooms - 1)
		{
			int randomNumber = rand() % 3;

			if (randomNumber <= 1)
			{
				int randomEquipment = rand() % 4;
				{
					if (randomEquipment == 0)
					{
						EmptyRoom emptyRoom(x,true, false, false, false,Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 1)
					{
						EmptyRoom emptyRoom(x,false, true, false, false, Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 2)
					{
						EmptyRoom emptyRoom(x,false, false, true, false, Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 3)
					{
						EmptyRoom emptyRoom(x,false, false, false, true, Empty);
						Map[x] = emptyRoom;
					}
				}

			}
			else
			{
				int randomEnemy = rand() % 3;

				if (randomEnemy == 0)
				{
					MonsterRoom monsterRoom(x,true, Goblin, Monster);
					Map[x] = monsterRoom;
				}
				if (randomEnemy == 1)
				{
					MonsterRoom monsterRoom(x,true, Oger, Monster);
					Map[x] = monsterRoom;
				}
				if (randomEnemy == 2)
				{
					MonsterRoom monsterRoom(x,true, Cyclops, Monster);
					Map[x] = monsterRoom;
				}
			}
		}
		else
		{
			TreasureRoom treasureRoom(x, Treasure);
			Map[x] = treasureRoom;
		}
	}
}


std::string RoomGenerator::getDescription()
{
	return description;
}

int RoomGenerator::getRoomNumber()
{
	return roomNumber;
}

RoomType RoomGenerator::getRoomType()
{
	return aroomType;
}

void RoomGenerator::checkItemPickUP(int currentRoomNumber)
{
	if (!bAlreadyVisited[currentRoomNumber])
	{
		char yesOrNo = 'a';
		if (Map[currentRoomNumber].bHasHealthPotion)
		{
			std::cout << "You have found a Health potion. \n";
			yesOrNo = userInput.getYesNo();
			if (yesOrNo)
			{
				bHasHealthPotion = false;
				playerMonk.AddItemToInventory("Health Potion");
				std::cout << "You have added a health potion to your inventory. \n";
				playerMonk.DisplayInventory();
			}
		}
		else if (Map[currentRoomNumber].bHasBomb)
		{
			std::cout << "You have found a Bomb. \n";
			yesOrNo = userInput.getYesNo();
			if (yesOrNo)
			{
				bHasBomb = false;
				playerMonk.AddItemToInventory("Bomb");
				std::cout << "You have added a Bomb to your inventory. \n";
				playerMonk.DisplayInventory();
			}
		}
		else if (Map[currentRoomNumber].bHasStaff)
		{
			std::cout << "You have found a Staff. \n";
			yesOrNo = userInput.getYesNo();
			if (yesOrNo)
			{
				bHasStaff = false;
				playerMonk.AddItemToInventory("Staff");
				std::cout << "You have added a Staff to your inventory. \n";
				playerMonk.DisplayInventory();
			}
		}
		else if (Map[currentRoomNumber].bHasArmour)
		{
			std::cout << "You have found Armour. \n";
			yesOrNo = userInput.getYesNo();
			if (yesOrNo)
			{
				bHasArmour = false;
				playerMonk.AddItemToInventory("Armour");
				std::cout << "You have added a armour to your inventory. \n";
				playerMonk.DisplayInventory();
			}
		}
	}
	else
	{
		
	}
	
}

void RoomGenerator::spawnPlayer()
{
	bool bvalidInput = false;
	playerMonk.setPlayerLocation(0);
	int currentPlayerLocation = 0;
	std::cout << "You are in room: " << 0 << ". " << Map[0].getDescription();
	do
	{
		if (userInput.getMovementDirection() == "North" && Map[0].bCanMoveNorth)
		{
			bvalidInput = true;
			bAlreadyVisited[0] = true;
			movePlayer(currentPlayerLocation + 1);
		}
		else
		{
			std::cout << "You cannot go South here. \n";
		}
	} while (!bvalidInput);
}



void RoomGenerator::movePlayer(int locationToMoveTo)
{
	int currentRoomNumber = locationToMoveTo;
	bool bvalidInput = false;
	std::cout << "You are in room: " << currentRoomNumber << ". " << Map[currentRoomNumber].getDescription();
	playerMonk.setPlayerLocation(currentRoomNumber);

	if (Map[locationToMoveTo].getRoomType() == Empty)
	{
		checkItemPickUP(currentRoomNumber);
	}
	do
	{
		std::string movementDirection = userInput.getMovementDirection();
		if (movementDirection == "North" && Map[locationToMoveTo].bCanMoveNorth)
		{
			bAlreadyVisited[currentRoomNumber] = true;
			movePlayer(playerMonk.getPlayerLocation() + 1);
			bvalidInput = true;
		}
		if (movementDirection == "South" && Map[locationToMoveTo].bCanMoveSouth)
		{
			bAlreadyVisited[currentRoomNumber] = true;
			movePlayer(playerMonk.getPlayerLocation() - 1);
			bvalidInput = true;
		}
	} while (!bvalidInput);
}

