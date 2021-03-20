#pragma once
#include "UserInput.h"
#include "PlayerMonk.h"
#include "RoomGenerator.h"
#include "Enums.h"
class PlayerMovement
{
	UserInput userInput;
	PlayerMonk playerMonk;
	RoomGenerator roomGenerator;
private:
	int Map[3][3];
	int playerLoaction = 7;

public:
	PlayerMovement();

	int getPlayerLoaction();

	void setPlayerLoaction(int location);

	void InitaliseMap();

	void DisplayMap();

	void SpawnPlayer();

	void MovePlayer();

	void MoveNorth(int x, int y);

	void MoveSouth(int x, int y);

	void MoveEast(int x, int y);

	void MoveWest(int x, int y);
};

