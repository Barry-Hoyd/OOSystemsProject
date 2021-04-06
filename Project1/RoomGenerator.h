#pragma once


#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Enums.h"
#include "Enemy.h"
#include "FileReadWrite.h"
#include "PlayerMonk.h"
#include "UserInput.h"

static PlayerMonk playerMonk;
static UserInput userInput;
static Enemy enemy;
static FileReadWrite fileReadWrite;

class RoomGenerator
{
public:
	int numberOfRooms = 9;
	int numberOfEnemies = 3;
	bool bCanMoveNorth = false;
	bool bCanMoveSouth = false;
	int roomNumber = 0;
	bool bAlreadySpawned = false;
	bool bHasHealthPotion = false;
	bool bHasBomb = false;
	bool bHasStaff = false;
	bool bHasArmour = false;
	bool bHasKey = false;
	bool bAlreadyVisited[15] = {};
	std::string description;
	RoomGenerator* Map;
	RoomType CurrentRoomType;
	EnemyType enemyRoomType;

	void generateMap();

	std::string getDescription();

	int getRoomNumber();

	RoomType getRoomType();

	EnemyType getEnemyType(int roomNumber);

	void checkItemPickUP(int currentRoomNumber);

	void checkIfRoomLocked(int currentRoomNumber);

	void spawnPlayer();

	void playerAction(int currentRoomNumber);

	void roomEventGenerator(int locationToMoveTo);

	void movePlayerDirection(int currentRoomNumber);

	void beginCombat(EnemyType enemyType);

	void combatLoop(Enemy enemy);

	void displayCombatStats(Enemy enemy);
};

class SpawnRoom : public RoomGenerator
{
public:
	SpawnRoom(RoomType roomType)
	{
		CurrentRoomType = roomType;
		roomNumber = 0;
		bCanMoveNorth = true;
		description = "This is the first room, there is a door in the North Wall. \n";
	}
};

class EmptyRoom : public RoomGenerator
{
public:
	EmptyRoom(int roomNumber, bool HasHealthPotion, bool HasBomb, bool HasStaff, bool HasArmour, RoomType roomType)
	{
		CurrentRoomType = roomType;
		bCanMoveNorth = true;
		bCanMoveSouth = true;
		this->bHasHealthPotion = HasHealthPotion;
		this->bHasBomb = HasBomb;
		this->bHasStaff = HasStaff;
		this->bHasArmour = HasArmour;
		description = "You enter an empty room the two ways out are North and back the way you came. \n";	
	}
};

class KeyRoom : public RoomGenerator
{
public:
	KeyRoom(int roomNumber, RoomType roomType)
	{
		CurrentRoomType = roomType;
		bCanMoveNorth = true;
		bCanMoveSouth = true;
		description = "You enter an empty room there is are doors in the north and south walls. \n";
		bHasKey = true;
	}
};

class TreasureRoom :public  RoomGenerator
{
public:
	TreasureRoom(int roomNumber, RoomType roomType)
	{
		CurrentRoomType = roomType;
		bCanMoveNorth = false;
		bCanMoveSouth = true;
		description = "You enter a room and you cannot believe your eyes it is over flowing with treasure. \n";
	}
};

class MonsterRoom : public RoomGenerator
{
public:
	MonsterRoom(int roomNumber, bool HasEnemy, EnemyType enemyType, RoomType roomType)
	{
		CurrentRoomType = roomType;
		enemyRoomType = enemyType;
		bCanMoveNorth = true;
		bCanMoveSouth = true;
		if (enemyType == Goblin)
		{
			description = "You enter a room and are attacked by a Goblin. \n";
		}
		else if (enemyType == Cyclops)
		{
			description = "You enter a room and are attacked by a Cyclops. \n";
		}
		else if (enemyType == Oger)
		{
			description = " You enter a room and are attacked by a Oger. \n";
		}
	}
};