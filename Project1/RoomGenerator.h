#pragma once
class RoomGenerator
{
private:
	enum roomType {
		Empty,
		Monster,
		Treasure
	};
	bool bHasEnemmy = false;
	bool bHasHealthPotion = false;
	bool bHasBomb = false;
	bool bHasStaff = false;
	bool bHasArmour = false;
	bool bHasKey = false;
	int roomloactionX = 0;
	int roomLocationY = 0;

public:

	void GenerateNewRoomLocation(int x, int y);

	void GenerateNewRoom(roomType RoomType);

	void GenerateRoomDescription();
};

