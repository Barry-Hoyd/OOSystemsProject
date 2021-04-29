#include "RoomGenerator.h"

void RoomGenerator::generateMap()
{
	srand((int)time(0)); //Used to randomise the room pattern each time
	Map = new RoomGenerator[numberOfRooms];
	for (int x = 0; x < numberOfRooms; x++)
	{
		if (x == 0) //first room is always spawn
		{
			SpawnRoom spawnRoom(Spawn);
			Map[0] = spawnRoom;
		}
		else if (x == numberOfRooms / 2) //halfway room is always key room
		{
			KeyRoom keyRoom(x, Key);
			Map[x] = keyRoom;
		}
		else if (x != numberOfRooms - 1) //for every room except the last make it empty or monster
		{
			if (x % 2 == 1 && x != numberOfRooms - 2)
			{
				int randomEquipment = rand() % 4; //used to randomise what equipment is in an empty room
				{
					if (randomEquipment == 0) //health potion
					{
						EmptyRoom emptyRoom(x, true, false, false, false, Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 1) //bomb
					{
						EmptyRoom emptyRoom(x, false, true, false, false, Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 2) //staff
					{
						EmptyRoom emptyRoom(x, false, false, true, false, Empty);
						Map[x] = emptyRoom;
					}
					else if (randomEquipment == 3) //armour
					{
						EmptyRoom emptyRoom(x, false, false, false, true, Empty);
						Map[x] = emptyRoom;
					}
				}
			}
			else
			{
				int randomEnemy = rand() % 3;//selects what monster will be in the room

				if (randomEnemy == 0) //goblin enemy
				{
					MonsterRoom monsterRoom(x, true, Goblin, Monster);
					Map[x] = monsterRoom;
					numberOfEnemies--;
				}
				if (randomEnemy == 1) //oger enemy
				{
					MonsterRoom monsterRoom(x, true, Oger, Monster);
					Map[x] = monsterRoom;
					numberOfEnemies--;
				}
				if (randomEnemy == 2) //cyclops enemy
				{
					MonsterRoom monsterRoom(x, true, Cyclops, Monster);
					Map[x] = monsterRoom;
					numberOfEnemies--;
				}

			}
		}
		else
		{
			TreasureRoom treasureRoom(x, Treasure); //final room is always treasure
			Map[x] = treasureRoom;
		}
	}
	setGameDifficulty(numberOfRooms); //sets the game difficulty in txt
}

void RoomGenerator::setGameDifficulty(int numberOfrooms)
{
	//sets the difficulty for the results screen
	if (numberOfrooms == 6)
	{
		difficulty = "Easy";
	}
	else if (numberOfrooms == 9)
	{
		difficulty = "Medium";
	}
	else
	{
		difficulty = "Hard";
	}
}
/*Getters & Setters for difficulty*/
std::string RoomGenerator::getGamedifficulty()
{
	return difficulty;
}

std::string RoomGenerator::getDescription()
{
	return description;
}
/*Getters & Setters for room info*/
int RoomGenerator::getRoomNumber()
{
	return roomNumber;
}

RoomType RoomGenerator::getRoomType()
{
	return CurrentRoomType;
}

EnemyType RoomGenerator::getEnemyType(int roomNumber)
{
	return this->enemyRoomType;
}

void RoomGenerator::checkItemPickUP(int currentRoomNumber)
{
	char yesOrNo = 'a';
	if (!bAlreadyVisited[currentRoomNumber]) //if the room hasn't been visited spawn item
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
				fileReadWrite.writeToFile("    Player picks up a health potion");
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
				fileReadWrite.writeToFile("    Player picks up a bomb");
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
				playerMonk.EquipStaff();
				fileReadWrite.writeToFile("    Player picks up a staff");
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
				playerMonk.EquipArmour();
				fileReadWrite.writeToFile("    Player picks up armour");
			}
		}

	}
	if (Map[currentRoomNumber].bHasKey && !playerMonk.getKey())
	{
		std::cout << "You have found a Key. \n \n";
		yesOrNo = userInput.getYesNo();
		if (yesOrNo)
		{
			playerMonk.AddItemToInventory("Key");
			bHasKey = false;
			std::cout << "You have added a key to your inventory. \n \n";
			fileReadWrite.writeToFile("    Player picks up a key");
		}
	}
}

void RoomGenerator::checkIfRoomLocked(int currentRoomNumber)
{
	//checks if the player has a key to unlock the door
	std::cout << "You approach a set of doors they are locked. \n";
	if (!playerMonk.getKey())
	{
		std::cout << "You need a key to open them, maybe its in the dungeon somewhere. \n";
	}
	else
	{
		std::cout << "You use the key you have found to unlock the doors. \n";
		std::cout << Map[currentRoomNumber].getDescription() << "\n";
	}
}

void RoomGenerator::spawnPlayer()
{
	//sets the players name and descriptiion
	std::string playerName = "";
	std::string playerDescription;
	std::cout << "Please enter a name for you character: ";
	std::cin >> playerName;
	cin.ignore();
	std::cout << "Please enter a description about your charcater: ";
	std::getline(std::cin, playerDescription);
	playerMonk.setName(playerName);
	playerMonk.setDesc(playerDescription);
	system("CLS");
	std::cout << "Your name is " << playerMonk.getName() << ".\n";
	std::cout << "A bit about you " << playerMonk.getDesc() << ".\n";
	std::cout << "You awaken in an empty room you have no idea how you got here but you know you must adventure to survive. \n";
	system("PAUSE");
	system("CLS");

	system("Color 0B");
	bool bvalidInput = false;
	playerMonk.setPlayerLocation(0);
	int currentPlayerLocation = 0;
	//PC filepath
	fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\EmptyRoom.txt");
	//Laptop filepath
	//fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\EmptyRoom.txt");
	std::cout << Map[0].getDescription() << "\n";
	playerMonk.DisplayPlayerStats();
	playerMonk.setNumberOfRoomsVisited();
	fileReadWrite.writeToFile("Visited spawn");
	playerAction(0);
}

void RoomGenerator::playerAction(int currentRoomNumber)
{
	//used to allow the player to select their action
	bool bvalidInput = false;
	int playerActionChoice = 0;
	bool playerAlreadyHealed = false;
	string itemToDrop = "";

	while (!bvalidInput)
	{
		playerActionChoice = userInput.getPlayerRoomAction();
		if (playerActionChoice == 1)
		{
			movePlayerDirection(currentRoomNumber);
		}
		else if (playerActionChoice == 2)
		{
			if (!playerAlreadyHealed)
			{
				fileReadWrite.writeToFile("    Player prays and heals to full");
				std::cout << "You have chosen to pray restoring your health to full! \n";
				playerAlreadyHealed = true;
				playerMonk.setCurrentHealth(playerMonk.getMaxHealth());
			}
			else
			{
				std::cout << "You have already prayed restoring your health to full in this room. Please select another action! \n";
			}
		}
		else if (playerActionChoice == 3)
		{
			if (playerMonk.getNumberOfItemsInInventory() > 0)
			{
				fileReadWrite.writeToFile("    Player chooses to drop an item on the floor");
				std::cout << "This is your inventory! \n";
				playerMonk.DisplayInventory();
				itemToDrop = userInput.getPlayerInventoryAction();
				if (itemToDrop == "Health")
				{
					playerMonk.dropHealthPotion();
					fileReadWrite.writeToFile("      Health potion dropped");
				}
				else if (itemToDrop == "Bomb")
				{
					playerMonk.dropBomb();
					fileReadWrite.writeToFile("      Unlit bomb dropped");
				}
				else if (itemToDrop == "Armour")
				{
					playerMonk.dropArmour();
					fileReadWrite.writeToFile("      Armour dropped");
				}
				else if (itemToDrop == "Staff")
				{
					playerMonk.dropStaff();
					fileReadWrite.writeToFile("      Staff dropped");
				}
				playerMonk.DisplayInventory();
			}
			else
			{
				std::cout << "Your inventory is empty so you cannot drop anything! \n";
			}
		}
		else if (playerActionChoice == 4)
		{
			fileReadWrite.writeToFile("    Player chooses to display their inventory");
			playerMonk.DisplayInventory();
		}
	}
}

void RoomGenerator::roomEventGenerator(int locationToMoveTo)
{
	int currentRoomNumber = locationToMoveTo;

	system("CLS");
	if (Map[currentRoomNumber].getRoomType() == Treasure) //if the next room is treasure room
	{
		fileReadWrite.writeToFile("  Visited Treasure Room");
		//PC filepath
		fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Treasure.txt");
		//Laptop filepath
		//fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\Treasure.txt");
		system("Color 0E");
		checkIfRoomLocked(currentRoomNumber);
		playerMonk.setNumberOfRoomsVisited();
		displayWinStats(true);
		system("PAUSE");
	}
	else
	{
		playerMonk.setPlayerLocation(currentRoomNumber);
		if (Map[currentRoomNumber].getRoomType() == Empty) //if the next room is an empty room
		{
			fileReadWrite.writeToFile("  Visited Empty Room");
			playerMonk.setNumberOfRoomsVisited();
			system("Color 0B");
			//PC filepath
			fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\EmptyRoom.txt");
			//Laptop filepath
			//fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\EmptyRoom.txt");
			std::cout << Map[currentRoomNumber].getDescription() << "\n";
			playerMonk.DisplayPlayerStats();
			std::cout << "\n";
			checkItemPickUP(currentRoomNumber); //checks if their is an item to pick up
			playerAction(currentRoomNumber);
		}
		else if (Map[currentRoomNumber].getRoomType() == Key) //if the next room is a key room
		{
			fileReadWrite.writeToFile("  Visited Key Room");
			playerMonk.setNumberOfRoomsVisited();
			system("Color 0B");
			//PC filepath
			fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\EmptyRoom.txt");
			//Laptop filepath
			//fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\EmptyRoom.txt");
			std::cout << Map[currentRoomNumber].getDescription() << "\n";
			playerMonk.DisplayPlayerStats();
			std::cout << "\n";
			checkItemPickUP(currentRoomNumber);
			playerAction(currentRoomNumber);
		}
		else if (Map[currentRoomNumber].getRoomType() == Monster) //if the next room is a monster room
		{
			fileReadWrite.writeToFile("  Visited Monster Room");
			playerMonk.setNumberOfRoomsVisited();
			system("Color 0C");
			beginCombat(Map[currentRoomNumber].getEnemyType(currentRoomNumber)); //start combat
			movePlayerDirection(currentRoomNumber);
			system("CLS");
		}
		else if (Map[currentRoomNumber].getRoomType() == Spawn)
		{
			fileReadWrite.writeToFile("  Visited Empty Room");
			playerMonk.setNumberOfRoomsVisited();
			system("Color 0B");
			//PC filepath
			fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\EmptyRoom.txt");
			//Laptop filepath
			//fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\EmptyRoom.txt");
			std::cout << Map[currentRoomNumber].getDescription() << "\n";
			playerMonk.DisplayPlayerStats();
			std::cout << "\n";
			playerAction(currentRoomNumber);
		}
	}
}

void RoomGenerator::movePlayerDirection(int currentRoomNumber)
{
	bool bvalidInput = false;
	do
	{
		std::string movementDirection = userInput.getMovementDirection(); //get player direction
		if (movementDirection == "North" && Map[currentRoomNumber].bCanMoveNorth) //if the room allows player to move north move them
		{
			fileReadWrite.writeToFile("Player Moves North");
			bAlreadyVisited[currentRoomNumber] = true;
			roomEventGenerator(playerMonk.getPlayerLocation() + 1);
		}
		if (movementDirection == "South" && Map[currentRoomNumber].bCanMoveSouth)
		{
			fileReadWrite.writeToFile("Player Moves South");
			bAlreadyVisited[currentRoomNumber] = true;
			system("CLS");
			if (playerMonk.getPlayerLocation() - 1 == 0)
			{
				roomEventGenerator(0);
			}
			else
			{
				roomEventGenerator(playerMonk.getPlayerLocation() - 1);
			}

			bvalidInput = true;
		}
		else
		{
			std::cout << "You cannot go South here! \n";
		}
	} while (!bvalidInput);
}

void RoomGenerator::beginCombat(EnemyType enemyType)
{
	fileReadWrite.writeToFile("    Combat begins!");
	if (enemyType == Goblin)
	{
		GoblinEnemy goblinEnemy;
		combatLoop(goblinEnemy);
	}
	else if (enemyType == Cyclops)
	{
		CyclopsEnemy cyclopsEnemy;
		combatLoop(cyclopsEnemy);
	}
	else if (enemyType == Oger)
	{
		OgerEnemy ogerEmeny;
		combatLoop(ogerEmeny);
	}
}

void RoomGenerator::combatLoop(Enemy enemy)
{
	bool playersTurn = true;
	bool validAction = false;
	playerMonk.setIsInCombat(true);
	while (!playerMonk.getDead() && !enemy.bIsDead)
	{

		if (playersTurn)
		{
			//PC filepath
			fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Enemy.txt");
			//Laptop filepath
			//fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\Enemy.txt");
			std::cout << "Players Turn \n";
			int actionChoice = 0;
			displayCombatStats(enemy);
			actionChoice = userInput.getPlayerCombatMove();
			switch (actionChoice)
			{
			case(1):
				fileReadWrite.writeToFile("      Player attacks");
				std::cout << "You have chosen to attack! \n";
				playerMonk.setIsAttacking(true);
				playerMonk.setIsDefending(false);
				if (playerMonk.Attack())
				{
					enemy.currentHealth -= (playerMonk.getDamage() - enemy.armour);
					fileReadWrite.writeToFile("        Player attack hits");
				}
				else
				{
					fileReadWrite.writeToFile("        Player attack misses");
				}
				validAction = true;
				break;
			case(2):
				std::cout << "You have chosen to defend! \n";
				fileReadWrite.writeToFile("      Player defends");
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
				itemToUse = userInput.getInventoryCombatControl();
				if (itemToUse == "Health")
				{
					playerMonk.UseHealthPotion();
					fileReadWrite.writeToFile("      Player uses an item");
					fileReadWrite.writeToFile("        Health potion");
				}
				else if (itemToUse == "Bomb")
				{
					playerMonk.UseBomb();
					enemy.setCurrentHealth(0);
					fileReadWrite.writeToFile("      Player uses an item");
					fileReadWrite.writeToFile("        Bomb");
				}
				else if (itemToUse == "None")
				{
					validAction = false;
				}
				system("PAUSE");
				break;
			}
			if (validAction)
			{
				playersTurn = false;
				system("PAUSE");
			}
			if (enemy.CheckDead())
			{
				playerMonk.setIsInCombat(false);
				std::cout << "Enemy defeated! \n";
				fileReadWrite.writeToFile("      Enemy defeated");
				playerMonk.setNumberOfEnemiesDefeated();
			}
		}
		else if (!playersTurn && !enemy.CheckDead())
		{
			system("CLS");
			//PC filepath
			fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Enemy.txt");
			//Laptop filepath
			//fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\Enemy.txt");
			displayCombatStats(enemy);
			std::cout << "Enemy Turn\n";
			if (enemy.getCombatMove())
			{
				fileReadWrite.writeToFile("      Enemy attacks");
				if (enemy.Attack(enemy.attackHitChance))
				{
					playerMonk.setCurrentHealth(playerMonk.getCurrentHealth() - (enemy.damage - playerMonk.getArmour()));
					fileReadWrite.writeToFile("        Enemy attack hits");
					playerMonk.setDead(true);
				}
				else
				{
					fileReadWrite.writeToFile("        Enemy attack misses");
				}
			}
			else
			{
				fileReadWrite.writeToFile("      Enemy defends");
				enemy.Defend();
			}
			if (playerMonk.getDead())
			{
				std::cout << "You have died! \n";
				fileReadWrite.writeToFile("      Player Dead");
				system("PAUSE");
				system("CLS");
				displayWinStats(false);
				//playersTurn = false;
			}
			system("PAUSE");
			system("CLS");
			playersTurn = true;
		}
	}
}

void RoomGenerator::displayCombatStats(Enemy enemy)
{
	std::cout << "Player Health: " << playerMonk.getCurrentHealth() << "                   " << "Enemy Health: " << enemy.currentHealth << "\n";
	std::cout << "Player Damage: " << playerMonk.getDamage() << "                  " << "Enemy Damage: " << enemy.damage << "\n";
	std::cout << "Player Armour: " << playerMonk.getArmour() << "                   " << "Enemy Armour: " << enemy.armour << "\n";
	std::cout << "\n";
}

void RoomGenerator::displayWinStats(bool won)
{
	fileReadWrite.writeToFile("\n Game Stats \n");
	std::cout << "Monk Name: " << playerMonk.getName() << "\n";
	fileReadWrite.writeToFile("Monk Name: " + playerMonk.getName());
	std::cout << "Monk's Description: " << playerMonk.getDesc() << "\n";
	fileReadWrite.writeToFile("Monk's Description: " + playerMonk.getDesc());
	std::cout << "Monk's Health: " << playerMonk.getCurrentHealth() << "\n";
	fileReadWrite.writeToFile("Monk's Health: " + std::to_string(playerMonk.getCurrentHealth()));
	std::cout << "Monk's Damage: " << playerMonk.getDamage() << "\n";
	fileReadWrite.writeToFile("Monk's Damage: " + std::to_string(playerMonk.getDamage()));
	std::cout << "Monk's Armour: " << playerMonk.getArmour() << "\n";
	fileReadWrite.writeToFile("Monk's Armour: " + std::to_string(playerMonk.getArmour()));
	std::cout << "Rooms Visited: " << playerMonk.getNumberOfRoomsVisited() << "\n";
	fileReadWrite.writeToFile("Rooms Visited: " + std::to_string(playerMonk.getNumberOfRoomsVisited()));
	std::cout << "Enemeies Defeated: " << playerMonk.getNumberOfEnemiesDefeated() << "\n";
	fileReadWrite.writeToFile("Enemeies Defeated: " + std::to_string(playerMonk.getNumberOfEnemiesDefeated()));
	std::cout << "Game Difficulty: " << getGamedifficulty() << "\n";
	if (won)
	{
		std::cout << "Game Result: Won \n";
		fileReadWrite.writeToFile("Game Result: Won");
	}
	else
	{
		std::cout << "Game Result: Lost \n";
		fileReadWrite.writeToFile("Game Result : Lost");
	}
	std::cout << "For More Infomation - Check Out The Game Logs \n";
	fileReadWrite.writeToFile("Thanks for playing!");
	exit(0);
}

