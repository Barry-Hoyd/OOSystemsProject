// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "RoomGenerator.h"
#include "FileReadWrite.h"


FileReadWrite fileReadWrite;

RoomGenerator roomGen;

void MainGame()
{
    std::string playerName = "";
    std::string playerDescription = "";
    std::cout << "Please enter a name for you character: ";
    std::cin >> playerName;
    std::cout << "Please enter a description about your charcater: ";
    std::cin >> playerDescription;
    playerMonk.setName(playerName);
    playerMonk.setDesc(playerDescription);
    system("CLS");

    std::cout << "Your name is " << playerMonk.getName() << ".\n";
    std::cout << "A bit about you " << playerMonk.getDesc() << ".\n";
    std::cout << "There will be " << roomGen.numberOfRooms-1 << " rooms.\n";
    std::cout << "There will be " << roomGen.numberOfEnemies << " enemies.\n";
    system("PAUSE");
    system("CLS");
    std::cout << "You awaken in an empty room you have no idea how you got here but you know you must adventure to survive. \n";
    roomGen.GenerateMap();
    roomGen.spawnPlayer();
}

void Menu()
{
    system("CLS");
    int menuFunction = 0;
    fileReadWrite.DisplayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Menu.txt");
    menuFunction = userInput.getPlayerAction();
    system("CLS");
    switch (menuFunction)
    {
    case(1):
        std::cout << "Play Game \n";
        break;
    case(2):
        fileReadWrite.DisplayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Difficutly.txt");
        menuFunction = userInput.getPlayerAction();
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
        fileReadWrite.DisplayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Rules.txt");
        menuFunction = userInput.getPlayerAction();
        Menu();
        break;
    case(4):
        exit(0);
        break;
    }
}



int main()
{
    Menu();
    bool bGameOver = false;
    while (!bGameOver)
    {
        MainGame();
    }
    
}


