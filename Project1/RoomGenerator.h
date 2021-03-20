#pragma once
#include "Enums.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PlayerMonk.h"
#include "UserInput.h"

class RoomGenerator
{
public:
	
	bool bCanMoveNorth = false;
	bool bCanMoveSouth = false;
	int roomNumber = 0;
	bool bAlreadySpawned = false;
	bool bHasHealthPotion = false;
	bool bHasBomb = false;
	bool bHasStaff = false;
	bool bHasArmour = false;
	bool bAlreadyVisited[100] = {};
	std::string description;
	RoomGenerator* Map;
	RoomType aroomType;

	void GenerateMap(int numberOfRooms);

	std::string getDescription();

	int getRoomNumber();

	RoomType getRoomType();

	void checkItemPickUP(int currentRoomNumber);

	void spawnPlayer();

	void movePlayer(int locationToMoveTo);
};

class SpawnRoom : public RoomGenerator
{
public:
	SpawnRoom(RoomType roomType)
	{
		aroomType = roomType;
		roomNumber = 0;
		bCanMoveNorth = true;
		description = "This is an empty room, there is a door in the North Wall. \n";
	}
};

class EmptyRoom : public RoomGenerator
{
public:
	EmptyRoom(int roomNumber, bool HasHealthPotion, bool HasBomb, bool HasStaff, bool HasArmour, RoomType roomType)
	{
		aroomType = roomType;
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
		aroomType = roomType;
		bCanMoveNorth = true;
		bCanMoveSouth = true;
		description = "You enter an empty room there is are doors in the north and south walls. After searching you find a key on the floor. Would you like to pick it up? \n";
		bool bHasKey = true;
	}
};

class TreasureRoom :public  RoomGenerator
{
public:
	TreasureRoom(int roomNumber, RoomType roomType)
	{
		aroomType = roomType;
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
		aroomType = roomType;
		bCanMoveNorth = true;
		bCanMoveSouth = true;
		bool bHasEnemy = HasEnemy;
		if (enemyType == Goblin)
		{
			description = "You enter a room and are attacked by a Goblin. ";
			description += "\n";
		}
		else if (enemyType == Cyclops)
		{
			description = " You enter a room and are attacked by a Cyclops. ";
			description += "\n";
		}
		else if (enemyType == Oger)
		{
			description = " You enter a room and are attacked by a Oger. ";
			description += "\n";
		}
		
	}

};