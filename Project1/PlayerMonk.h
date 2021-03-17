#pragma once
#include <iostream>
#include <string>
class PlayerMonk
{
private: 
	/*Health & Armour*/
	int currentHealth = 15;
	const int MAX_HEALTH = 15;
	bool bCurrentlyHealing = false;
	bool bIsDead = false;
	/*Player Movement*/
	int playerMap[3][3];
	int playerCurrentRoomNumber = 7;
	/*Player Combat Stats*/
	int armour = 0;
	int damage = 3;
	bool isAttacking = false;
	bool isDefending = false;
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

	/*Player Health Getters & Setters*/
	int getCurrentHealth();

	void setCurrentHealth(int amount);

	const int getMaxHealth();
	
	bool getCurrentlyHealing();

	void setCurrentlyHealing(bool isTrue, int amount);

	bool getDead();

	void setDead(bool isTrue);

	/*Player Inventory FrameWork*/
	void DisplayInventory();

	void AddItemToInventory(std::string ItemToAdd);

	void RemoveItemFromInventory(std::string ItemToRemove);

	bool CheckInventoryForItem(std::string itemToCheckFor);

	/*Consumables & Weapons*/
	void setHasHealthPotion(bool isTrue);

	void UseHealthPotion();

	void setHasBomb(bool isTrue);

	void UseBomb();

	void setHasArmour(bool isTrue);

	void EquipArmour();

	void setHasStaff(bool isTrue);

	void EquipStaff();

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

	void Attack();
};

