// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Enemy.h"
#include "Enums.h"
#include "RoomGenerator.h"
#include "FileReadWrite.h"

//UserInput userInput;
FileReadWrite fileReadWrite;
UserInput mainUserInput;
void Menu()
{
    system("CLS");
    int menuFunction = 0;
    fileReadWrite.DisplayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Menu.txt");
    menuFunction = mainUserInput.getPlayerAction();
    system("CLS");
    switch (menuFunction)
    {
    case(1):
        std::cout << "Play Game";
        break;
    case(2):
        fileReadWrite.DisplayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Difficutly.txt");
        menuFunction = mainUserInput.getPlayerAction();
        Menu();
        break;
    case(3):
        fileReadWrite.DisplayFile("C:\\Users\\boydh\\source\\repos\\Project1\\Rules.txt");
        menuFunction = mainUserInput.getPlayerAction();
        Menu();
        break;
    case(4):
        exit(0);
        break;
    }
}

int main()
{
    
    

    //std::cout << "You awaken in an empty room you have no idea how you got here but you know you must adventure to survive. \n";
    //RoomGenerator roomGen;
    //roomGen.GenerateMap(11);
   // roomGen.spawnPlayer();
    

    bool bGameOver = false;
    Menu();

    //playerMovement.InitaliseMap();
    //playerMovement.SpawnPlayer();
   /* while (!bGameOver)
    {
        playerMovement.MovePlayer();
        playerMovement.DisplayMap();

    }*/




   /* userInput.getMovementDirection();
    userInput.getPlayerAction();
    userInput.getYesNo();
    */
    

    /*std::cout << "Goblins current health: " << goblin.getCurrentHealth() << "\n";
    std::cout << "oger current health: " << oger.getCurrentHealth() << "\n";
    std::cout << "cyclops current health: " << cyclops .getCurrentHealth() << "\n";
    std::cout << "\n";

    goblin.getCombatMove();

    playerMonk.AddItemToInventory("Health Potion");
    playerMonk.AddItemToInventory("Armour");
    playerMonk.AddItemToInventory("Bomb");
    playerMonk.AddItemToInventory("Staff");
    playerMonk.DisplayInventory();
    std::cout << "\n";

    std::cout << "Player inital stats: " << "\n";
    std::cout << "Players Current Health: " << playerMonk.getCurrentHealth() << "\n";
    std::cout << "Players Current Armour: " << playerMonk.getArmour() << "\n";
    std::cout << "Players Current Damage: " << playerMonk.getDamage() << "\n";

    std::cout << "\n";

    std::cout << "Player takes Damage" << "\n";
    playerMonk.setCurrentHealth(20);
    std::cout << "Players Current Health: " << playerMonk.getCurrentHealth() << "\n";

    std::cout << "\n";

    playerMonk.UseBomb();
    std::cout << "\n";
    playerMonk.DisplayInventory();

    std::cout << "\n";

    playerMonk.UseHealthPotion();
    std::cout << "Players Current Health: " << playerMonk.getCurrentHealth() << "\n";
    std::cout << "\n";
    playerMonk.DisplayInventory();

    std::cout << "\n";

    playerMonk.EquipArmour();
    std::cout << "Players Current Armour: " << playerMonk.getArmour() << "\n";
    std::cout << "\n";

    playerMonk.EquipStaff();
    std::cout << "Players Current Damage: " << playerMonk.getDamage() << "\n";
    std::cout << "\n";
    */
}


