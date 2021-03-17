#include "RoomGenerator.h"
#include <iostream>
#include <stdlib.h>

void RoomGenerator::GenerateNewRoomLocation(int x, int y)
{
	roomloactionX = x;
	roomLocationY = y;

	if (roomloactionX == 2 && roomLocationY == 0 || roomloactionX == 0 && roomLocationY == 0 || roomloactionX == 2 && roomLocationY == 1 || roomloactionX == 1 && roomLocationY == 2)
	{
		GenerateNewRoom(Empty);
	}
	if (roomloactionX == 1 && roomLocationY == 0 || roomloactionX == 1 && roomLocationY == 1 || roomloactionX == 2 && roomLocationY == 2 || roomloactionX == 0 && roomLocationY == 2)
	{
		GenerateNewRoom(Monster);
	}
}

void RoomGenerator::GenerateNewRoom(roomType RoomType)
{
	if (RoomType == Empty)
	{
		GenerateRoomDescription();
	}
	if (RoomType == Monster)
	{
		GenerateRoomDescription();
	}
}

void RoomGenerator::GenerateRoomDescription()
{

	if (roomloactionX == 0 && roomLocationY == 0)
	{
		std::cout << "You enter an empty room the only door in the room is the one which you can through." << "\n" << "After searching around you have find a key." << "\n";
	}
	if (roomloactionX == 1 && roomLocationY == 0)
	{
		std::cout << "You enter a room the only other door in the room is in front of you." << "\n" << "As you approach the door a smelly ogre jumps out and attacks you." << "\n" << "Combat Started" << "\n";
	}
	if (roomloactionX == 1 && roomLocationY == 0)
	{
		std::cout << "You enter an empty room there is a door in the north wall which you can go through." << "\n" << "After searching around you have find a health potion." << "\n";
	}
	if (roomloactionX == 0 && roomLocationY == 1)
	{
		std::cout << "You cannot believe your eyes a room filled to the brim with treasure." << "\n" << "There is also what appears to be a way out." << "\n";
	}
	if (roomloactionX == 1 && roomLocationY == 1)
	{
		std::cout << "You enter a room the only other door in the room is in front of you." << "\n" << "As you approach the door a dumb cyclops jumps out and attacks you." << "\n" << "Combat Started" << "\n";
	}
	if (roomloactionX == 2 && roomLocationY == 1)
	{
		std::cout << "You enter an empty room and see doors to your North, Eastand West." << "\n";
	}
	if (roomloactionX == 2 && roomLocationY == 0)
	{
		std::cout << "You enter aroom the only door in the room is the one which you can through." << "\n" << "After searching around are attacked by a goblin." << "\n" << "Combat Started" << "\n";
	}
	if (roomloactionX == 1 && roomLocationY == 2)
	{
		std::cout << "You enter an empty room there is a door in the north wall which you can go through." << "\n" << "After searching around you have find a staff and a bomb." << "\n";
	}
	if (roomloactionX == 2 && roomLocationY == 2)
	{
		std::cout << "You enter a room there is a door in the north wall." << "\n" << "Whilst you approach it a goblin attacks you." << "\n" << "Combat Started" << "\n";
	}
}
