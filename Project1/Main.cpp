// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "RoomGenerator.h"

RoomGenerator roomGen;

void Menu()
{
    system("CLS");
    int menuFunction = 0;
    //PC filepath
    fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Menu.txt");
    //Laptop filepath
    //fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\Menu.txt");
    cout << "Option: ";
    menuFunction = userInput.getPlayerAction();
    system("CLS");
    switch (menuFunction)
    {
    case(1):
        std::cout << "Play Game \n";
        break;
    case(2):
        //PC filepath
        fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Difficutly.txt");
        //Laptop filepath
        //fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\Difficutly.txt");
        cout << "Option: ";
        menuFunction = userInput.getPlayerAction();
        //sets the difficulty of the game
        if (menuFunction == 1)
        {
            roomGen.numberOfRooms = 6;
            roomGen.numberOfEnemies = 2;
        }
        else  if (menuFunction == 2)
        {
            roomGen.numberOfRooms = 9;
            roomGen.numberOfEnemies = 3;
        }
        else  if (menuFunction == 3)
        {
            roomGen.numberOfRooms = 12;
            roomGen.numberOfEnemies = 4;
        }
        Menu();
        break;
    case(3):
        //PC filepath
        fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Rules.txt");
        //Laptop filepath
        //displays the rules
        //fileReadWrite.displayFile("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\Rules.txt");
        system("PAUSE");
        Menu();
        break;
    case(4):
        exit(0);
        break;
    }
}

int main()
{
    //clears gamelog and begins the game
    fileReadWrite.clearGameLog();
    system("Color 09");
    Menu();
    roomGen.generateMap();
    roomGen.spawnPlayer();
}


