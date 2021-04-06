#include "PlayerMonk.h"
std::string PlayerMonk::getName()
{
	return this->name;
}

void PlayerMonk::setName(std::string name)
{
	this->name = name;
}

std::string PlayerMonk::getDesc()
{
	return this->description;
}

void PlayerMonk::setDesc(std::string desc)
{
	this->description = desc;
}

/*Players Stats*/
int PlayerMonk::getCurrentHealth()
{
	return this->currentHealth;
}

void PlayerMonk::setCurrentHealth(int amount)
{
	this->currentHealth = amount;
}

const int PlayerMonk::getMaxHealth()
{
	return this->MAX_HEALTH;
}

bool PlayerMonk::getDead()
{
	return this->bIsDead;
}

void PlayerMonk::setDead(bool isTrue)
{
	if (currentHealth <= 0)
	{
		this->bIsDead = true;
	}
}

void PlayerMonk::DisplayPlayerStats()
{
	std::cout << "Player Health: " << getCurrentHealth() << "\n";
	std::cout << "Player Damage: " << getDamage() << "\n";
	std::cout << "Player Armour: " << getArmour() << "\n";
}

/*Player Location*/
int PlayerMonk::getPlayerLocation()
{
	return this->playerLocation;
}

void PlayerMonk::setPlayerLocation(int newLocation)
{
	this->playerLocation = newLocation;
}

/*Player Inventory Functions*/
void PlayerMonk::DisplayInventory()
{
	if (numberOfItemsInInventory > 0)
	{
		for (int i = 0; i < inventorySize; i++)
		{
			if (inventory[i] != "")
			{
				std::cout << i+1 << ". " << inventory[i] << "\n";
			}
		}
	}
	else
	{
		std::cout << "\n" << "Your Inventory Is Empty \n";
	}
}

void PlayerMonk::AddItemToInventory(std::string ItemToAdd)
{
	if (numberOfItemsInInventory < 4)
	{
		for (int i = 0; i < inventorySize; i++)
		{
			if (inventory[i] == "")
			{
				inventory[i].assign(ItemToAdd);
				numberOfItemsInInventory++;
				if (ItemToAdd == "Health Potion")
				{
					setHasHealthPotion(true);
				}
				else if (ItemToAdd == "Bomb")
				{
					setHasBomb(true);
				}
				else if (ItemToAdd == "Armour")
				{
					setHasArmour(true);
				}
				else if (ItemToAdd == "Staff")
				{
					setHasStaff(true);
				}
				else if (ItemToAdd == "Key")
				{
					setHasKey(true);
				}
				break;
			}
		}
	}
	else
	{
		std::cout << "Your Inventory is Full" << "\n";
	}
}

void PlayerMonk::RemoveItemFromInventory(std::string ItemToRemove)
{
	if (numberOfItemsInInventory > 0)
	{
		for (int i = 0; i < inventorySize; i++)
		{
			if (inventory[i] == ItemToRemove)
			{
				inventory[i].assign("");
				numberOfItemsInInventory--;
				if (ItemToRemove == "Health Potion")
				{
					setHasHealthPotion(false);
				}
				else if (ItemToRemove == "Bomb")
				{
					setHasBomb(false);
				}
				else if (ItemToRemove == "Armour")
				{
					setHasArmour(false);
				}
				else if (ItemToRemove == "Staff")
				{
					setHasStaff(false);
				}
				break;
			}
		}
	}
	else
	{
		std::cout << "Your Inventory Is Empty" << "\n";
	}
}

bool PlayerMonk::CheckInventoryForItem(std::string itemToCheckFor)
{
	if (numberOfItemsInInventory > 0)
	{	
			if (inventory->find(itemToCheckFor))
			{
				return true;
			}
			else
			{
				return false;
			}	
	}
	else
	{
		std::cout << "Your Inventory Is Empty" << "\n";
	}
}

int PlayerMonk::getNumberOfItemsInInventory()
{
	return numberOfItemsInInventory;
}

/*Player Item Usage*/
void PlayerMonk::setHasHealthPotion(bool isTrue)
{
	this->bHasHealthPotion = isTrue;
}

void PlayerMonk::UseHealthPotion()
{
	if (bHasHealthPotion)
	{
		std::cout << "Player uses Healing Potion! " << "\n";
		setCurrentHealth(MAX_HEALTH);
		RemoveItemFromInventory("Health Potion");
	}
}

void PlayerMonk::dropHealthPotion()
{
	RemoveItemFromInventory("Health Potion");
	std::cout << "You have dropped a Health Potion on the floor! \n";
}

void PlayerMonk::setHasBomb(bool isTrue)
{
	this->bHasBomb = isTrue;
}

void PlayerMonk::UseBomb()
{
	if (bHasBomb)
	{
		std::cout << "Player drops a bomb" << "\n";
		RemoveItemFromInventory("Bomb");
	}
}

void PlayerMonk::dropBomb()
{
	RemoveItemFromInventory("Bomb");
	std::cout << "You have dropped an unlit Bomb on the floor! \n";
}

void PlayerMonk::setHasArmour(bool isTrue)
{
	this->bHasArmour = isTrue;
}

void PlayerMonk::EquipArmour()
{
	if (bHasArmour)
	{
		std::cout << "You equip armour and increase your armour by 2 points! \n";
		armour = 2;
	}
}

void PlayerMonk::dropArmour()
{
	RemoveItemFromInventory("Armour");
	std::cout << "You have dropped Armour on the floor! \n";
}

void PlayerMonk::setHasStaff(bool isTrue)
{
	this->bHasStaff = isTrue;
}

void PlayerMonk::EquipStaff(){
	if (bHasStaff)
	{
		std::cout << "You equip a staff and your damage increases by 3 points! \n";
		damage += 3;
	}
}

void PlayerMonk::dropStaff()
{
	RemoveItemFromInventory("Staff");
	std::cout << "You have dropped a Staff on the floor! \n";
}

bool PlayerMonk::getKey()
{
	return this->bHasKey;
}

void PlayerMonk::setHasKey(bool isTrue)
{
	this->bHasKey = isTrue;
}

/*Combat */
int PlayerMonk::getArmour()
{
	return this->armour;
}

int PlayerMonk::getDamage()
{
	return this->damage;
}

bool PlayerMonk::getIsAttacking()
{
	return this->isAttacking;
}

void PlayerMonk::setIsAttacking(bool isTrue)
{
	this->isAttacking = isTrue;
}

bool PlayerMonk::getIsDefending()
{
	return this->isDefending;
}

void PlayerMonk::setIsDefending(bool isTrue)
{
	this->isDefending = isTrue;
}

void PlayerMonk::Defend()
{
	if (isDefending && !isAttacking)
	{
		if (currentHealth < MAX_HEALTH)
		{
			std::cout << "You defend and recover 1hp! \n";
			setCurrentHealth(currentHealth + 1);
		}
		else
		{
			std::cout << "You defend but are already at max hp! \n";
		}	
	}
}

bool PlayerMonk::Attack()
{
	if (!isDefending && isAttacking)
	{
		srand((unsigned)time(0)); //Used to randomise the attack pattern each time
		int attackHitChance = rand() % 2;
		if (attackHitChance == 0)
		{
			std::cout << "You attack and hit! \n";
			return true;
		}
		else
		{
			std::cout << "You attack and miss! \n";
			return false;
		}
	}
}

void PlayerMonk::setIsInCombat(bool istrue)
{
	bIsInCombat = istrue;
}

bool PlayerMonk::getIsInCombat()
{
	return bIsInCombat;
}





