#include "PlayerMonk.h"

/*Sets Player Health*/
int PlayerMonk::getCurrentHealth()
{
	return currentHealth;
}

void PlayerMonk::setCurrentHealth(int amount)
{
	currentHealth = amount;
}

const int PlayerMonk::getMaxHealth()
{
	return 0;
}

bool PlayerMonk::getCurrentlyHealing()
{
	return bCurrentlyHealing;
}

void PlayerMonk::setCurrentlyHealing(bool isTrue)
{
	bCurrentlyHealing = isTrue;
	if (bCurrentlyHealing)
	{
		setCurrentHealth(MAX_HEALTH);
	}
}

bool PlayerMonk::getDead()
{
	return bIsDead;
}

void PlayerMonk::setDead(bool isTrue)
{
	if (currentHealth <= 0)
	{
		bIsDead = true;
	}
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
				std::cout << inventory[i] << "\n";
			}
		}
	}
	else
	{
		std::cout << "\n" << "Your Inventory Is Empty";
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

void PlayerMonk::setHasHealthPotion(bool isTrue)
{
	bHasHealthPotion = isTrue;
}

void PlayerMonk::UseHealthPotion()
{
	if (bHasHealthPotion)
	{
		std::cout << "Player uses Healing Potion :" << "\n";
		setCurrentlyHealing(true);
		RemoveItemFromInventory("Health Potion");
	}
}

void PlayerMonk::setHasBomb(bool isTrue)
{
	bHasBomb = isTrue;
}

void PlayerMonk::UseBomb()
{
	if (bHasBomb && CheckInventoryForItem("Bomb"))
	{
		std::cout << "Player drops a bomb" << "\n";
		RemoveItemFromInventory("Bomb");
	}
}

void PlayerMonk::setHasArmour(bool isTrue)
{
	bHasArmour = isTrue;
}

void PlayerMonk::EquipArmour()
{
	if (bHasArmour && CheckInventoryForItem("Armour"))
	{
		std::cout << "Player Equips Armour" << "\n";
		armour = 2;
	}
}

void PlayerMonk::setHasStaff(bool isTrue)
{
	bHasStaff = isTrue;
}

void PlayerMonk::EquipStaff()
{
	if (bHasStaff && CheckInventoryForItem("Staff"))
	{
		std::cout << "Player Equips A Staff" << "\n";
		damage = 3;
	}
}

int PlayerMonk::getArmour()
{
	return armour;
}

int PlayerMonk::getDamage()
{
	return damage;
}

bool PlayerMonk::getIsAttacking()
{
	return isAttacking;
}

void PlayerMonk::setIsAttacking(bool isTrue)
{
	isAttacking = isTrue;
	setIsDefending(false);
}

bool PlayerMonk::getIsDefending()
{
	return isDefending;
}

void PlayerMonk::setIsDefending(bool isTrue)
{
	isDefending = isTrue;
	setIsAttacking(false);
}


