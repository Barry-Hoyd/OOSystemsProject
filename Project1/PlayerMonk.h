#pragma once
#include <iostream>
#include <string>
class PlayerMonk
{
private: 
	/*Player Name & Description*/
	std::string name = "";
	std::string description = "";
	/*Health & Armour*/
	int currentHealth = 15;
	const int MAX_HEALTH = 15;
	bool bIsDead = false;
	/*Player Movement*/
	int playerLocation = 0;
	/*Player Combat Stats*/
	int armour = 0;
	int damage = 200;
	bool isAttacking = false;
	bool isDefending = false;
	bool bIsInCombat = false;
	/*Players Inventory*/
	int inventorySize = 4;
	int numberOfItemsInInventory = 0;
	std::string inventory[4] = {};
	/*Player Uses Item*/
	bool bHasHealthPotion = false;
	bool bHasBomb = false;
	bool bHasArmour = false;
	bool bHasStaff = false;
	bool bHasKey = false;
	
	
public:
	/*Player Name & Desc Getters & Setters*/
	std::string getName();

	void setName(std::string name);

	std::string getDesc();

	void setDesc(std::string desc);

	/*Player Health Getters & Setters*/
	int getCurrentHealth();

	void setCurrentHealth(int amount);

	const int getMaxHealth();

	bool getDead();

	void setDead(bool isTrue);

	void DisplayPlayerStats();

	/*Player Movement Getters & Setters*/

	int getPlayerLocation();

	void setPlayerLocation(int newLocation);

	/*Player Inventory FrameWork*/
	void DisplayInventory();

	void AddItemToInventory(std::string ItemToAdd);

	void RemoveItemFromInventory(std::string ItemToRemove);

	bool CheckInventoryForItem(std::string itemToCheckFor);

	int getNumberOfItemsInInventory();

	/*Consumables & Weapons*/
	void setHasHealthPotion(bool isTrue);

	void UseHealthPotion();

	void dropHealthPotion();

	void setHasBomb(bool isTrue);

	void UseBomb();

	void dropBomb();

	void setHasArmour(bool isTrue);

	void EquipArmour();

	void dropArmour();

	void setHasStaff(bool isTrue);

	void EquipStaff();

	void dropStaff();

	bool getKey();

	void setHasKey(bool isTrue);

	/*Combat stats*/

	int getArmour();

	int getDamage();

	bool getIsAttacking();

	void setIsAttacking(bool isTrue);

	bool getIsDefending();

	void setIsDefending(bool isTrue);

	void Defend();

	bool Attack();

	void setIsInCombat(bool istrue);

	bool getIsInCombat();
};

