#include "RoomGenerator.h"

void RoomGenerator::GenerateMap()
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
		else if (x == numberOfRooms / 2)
		{
			KeyRoom keyRoom(x, Key);
			Map[x] = keyRoom;
		}
		else if (x != numberOfRooms - 1)
		{
			if (x % 2 == 1 && x != numberOfRooms - 2)
			{
				int randomEquipment = rand() % 4;
				{
					if (randomEquipment == 0)
					{
						EmptyRoom emptyRoom(x, true, false, false, false, Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 1)
					{
						EmptyRoom emptyRoom(x, false, true, false, false, Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 2)
					{
						EmptyRoom emptyRoom(x, false, false, true, false, Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 3)
					{
						EmptyRoom emptyRoom(x, false, false, false, true, Empty);
						Map[x] = emptyRoom;
					}
				}
			}
			else
			{
				int randomEnemy = rand() % 3;

				if (randomEnemy == 0)
				{
					MonsterRoom monsterRoom(x, true, Goblin, Monster);
					Map[x] = monsterRoom;
					numberOfEnemies--;
				}
				if (randomEnemy == 1)
				{
					MonsterRoom monsterRoom(x, true, Oger, Monster);
					Map[x] = monsterRoom;
					numberOfEnemies--;
				}
				if (randomEnemy == 2)
				{
					MonsterRoom monsterRoom(x, true, Cyclops, Monster);
					Map[x] = monsterRoom;
					numberOfEnemies--;
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

EnemyType RoomGenerator::getEnemyType(int roomNumber)
{
	return this->aenemyType;
}

void RoomGenerator::checkItemPickUP(int currentRoomNumber)
{
	char yesOrNo = 'a';
	if (!bAlreadyVisited[currentRoomNumber])
	{

		if (Map[currentRoomNumber].bHasHealthPotion)
		{
			std::cout << "After searching you have found a Health potion. \n";
			yesOrNo = userInput.getYesNo();
			if (yesOrNo)
			{
				bHasHealthPotion = false;
				playerMonk.AddItemToInventory("Health Potion");
				std::cout << "You have added a health potion to your inventory. \n \n";
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
				std::cout << "You have added a Bomb to your inventory. \n \n";
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
				std::cout << "You have added a Staff to your inventory. \n \n";
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
				std::cout << "You have added a armour to your inventory. \n \n";
			}
		}
	}
	if (Map[currentRoomNumber].bHasKey)
	{
		std::cout << "You have found a Key. \n \n";
		yesOrNo = userInput.getYesNo();
		if (yesOrNo)
		{
			playerMonk.AddItemToInventory("Key");
			std::cout << "You have added a key to your inventory. \n \n";
		}
	}
}

void RoomGenerator::checkIfRoomLocked(int currentRoomNumber)
{
	std::cout << "You approach a set of doors they are locked. \n";
	if (!playerMonk.getKey())
	{
		std::cout << "You need a key to open them, maybe its in the dungeon somewhere. \n";
	}
	else 
	{
		std::cout << "You use the key you have found to unlock the doors. \n";
		std::cout << "You are in room: " << currentRoomNumber << ". " << Map[currentRoomNumber].getDescription();
	}
}

void RoomGenerator::spawnPlayer()
{
	bool bvalidInput = false;
	playerMonk.setPlayerLocation(0);
	int currentPlayerLocation = 0;
	std::cout << Map[0].getDescription() << "\n";
	playerMonk.DisplayPlayerStats();
	do
	{
		if (userInput.getMovementDirection() == "North" && Map[0].bCanMoveNorth)
		{
			bvalidInput = true;
			bAlreadyVisited[0] = true;
			system("CLS");
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
	system("CLS");
	if (Map[currentRoomNumber].getRoomType() == Treasure)
	{
		checkIfRoomLocked(currentRoomNumber);
	}
	else
	{
		std::cout << Map[currentRoomNumber].getDescription() << "\n";
		playerMonk.setPlayerLocation(currentRoomNumber);

		if (Map[currentRoomNumber].getRoomType() == Empty)
		{
			int playerActionChoice = 0;
			playerMonk.DisplayPlayerStats();
			std::cout << "\n";
			checkItemPickUP(currentRoomNumber);
			
			while (!bvalidInput)
			{
				playerActionChoice = userInput.getPlayerRoomAction();
				if (playerActionChoice == 1)
				{
					do
					{
						std::string movementDirection = userInput.getMovementDirection();
						if (movementDirection == "North" && Map[currentRoomNumber].bCanMoveNorth)
						{
							bAlreadyVisited[currentRoomNumber] = true;
							movePlayer(playerMonk.getPlayerLocation() + 1);
							system("CLS");
							bvalidInput = true;
						}
						if (movementDirection == "South" && Map[currentRoomNumber].bCanMoveSouth)
						{
							bAlreadyVisited[currentRoomNumber] = true;
							system("CLS");
							movePlayer(playerMonk.getPlayerLocation() - 1);
							bvalidInput = true;
						}
					} while (!bvalidInput);
				}
				else if (playerActionChoice == 2)
				{
					std::cout << "You have chosen to pray restoring your health to full! \n";
					playerMonk.setCurrentHealth(playerMonk.getMaxHealth());
				}
			}
		}
		else if (Map[currentRoomNumber].getRoomType() == Key)
		{
			playerMonk.DisplayPlayerStats();
			std::cout << "\n";
			checkItemPickUP(currentRoomNumber);
		}
		else if (Map[currentRoomNumber].getRoomType() == Monster)
		{
			BeginCombat(Map[currentRoomNumber].getEnemyType(currentRoomNumber));
		}
	}
}
	
void RoomGenerator::BeginCombat(EnemyType enemyType)
{
	if (enemyType == Goblin)
	{
		GoblinEnemy goblinEnemy;
		CombatLoop(goblinEnemy);
	}
	else if (enemyType == Cyclops)
	{
		CyclopsEnemy cyclopsEnemy;
		CombatLoop(cyclopsEnemy);
	}
	else if (enemyType == Oger)
	{
		OgerEnemy ogerEmeny;
		CombatLoop(ogerEmeny);
	}
}

void RoomGenerator::CombatLoop(Enemy enemy)
{
	bool playersTurn = true;
	bool validAction = false;
	playerMonk.setIsInCombat(true);
	
	while (!playerMonk.getDead() && !enemy.bIsDead)
	{
		if (playersTurn)
		{
			std::cout << "Players Turn \n";
			int actionChoice = 0;
			DisplayCombatStats(enemy);
			actionChoice = userInput.getPlayerCombatMove();
			switch (actionChoice)
			{
			case(1):
				std::cout << "You have chosen to attack! \n";
				playerMonk.setIsAttacking(true);
				playerMonk.setIsDefending(false);
				if (playerMonk.Attack())
				{
					enemy.currentHealth -= (playerMonk.getDamage() - enemy.armour);
				}
				validAction = true;
				break;
			case(2):
				std::cout << "You have chosen to defend! \n";
				playerMonk.setIsAttacking(false);
				playerMonk.setIsDefending(true);
				playerMonk.Defend();
				validAction = true;
				break;
			case(3):
				std::string itemToUse = "";
				std::cout << "You have chosen to use an item! \n";
				std::cout << "\n";
				playerMonk.DisplayInventory();
				itemToUse = userInput.getInventoryControl();
				if (itemToUse == "Health")
				{
					playerMonk.UseHealthPotion();
				}
				else if (itemToUse == "Bomb")
				{
					playerMonk.UseBomb();
					enemy.setCurrentHealth(0);
				}
				else if (itemToUse == "None")
				{
					validAction = false;
				}
				break;
			}
			if (enemy.CheckDead())
			{
				playerMonk.setIsInCombat(false);
				system("CLS");
				std::cout << "Enemy defeated! \n";
			}
			if (validAction)
			{
				playersTurn = false;
				system("PAUSE");
				system("CLS");
			}
			system("PAUSE");
			system("CLS");
		}
		else if (!playersTurn && !enemy.CheckDead())
		{
			std::cout << "Enemy Turn\n";
			if (enemy.getCombatMove())
			{
				if (enemy.Attack(enemy.attackHitChance))
				{
					playerMonk.setCurrentHealth(playerMonk.getCurrentHealth() - (enemy.damage - playerMonk.getArmour() ));
					playerMonk.setDead(true);
				}
			}
			else
			{
				enemy.Defend();
			}
			playersTurn = true;
		}
		if (playerMonk.getDead())
		{
			std::cout << "You have died! \n";
			system("PAUSE");
			exit(0);
		}
	}
}

void RoomGenerator::DisplayCombatStats(Enemy enemy)
{
	std::cout << "Player Health: " << playerMonk.getCurrentHealth() << "                   " << "Enemy Health: " << enemy.currentHealth << "\n";
	std::cout << "Player Damage: " << playerMonk.getDamage() << "                   " << "Enemy Damage: " << enemy.damage << "\n";
	std::cout << "Player Armour: " << playerMonk.getArmour() << "                   " << "Enemy Armour: " << enemy.armour << "\n";
	std::cout << "\n";
}

