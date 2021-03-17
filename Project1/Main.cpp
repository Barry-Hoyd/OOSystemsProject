// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "PlayerMonk.h"
#include "PlayerMovement.h"
#include "Enemy.h"
#include "UserInput.h"

int main()
{
    PlayerMonk playerMonk;
    PlayerMovement playerMovement;
    Goblin goblin;
    Oger oger;
    Cyclops cyclops;

    UserInput userInput;

    bool bGameOver = false;

    playerMovement.InitaliseMap();
    playerMovement.SpawnPlayer();
    while (!bGameOver)
    {
        playerMovement.MovePlayer();
        playerMovement.DisplayMap();

    }




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

