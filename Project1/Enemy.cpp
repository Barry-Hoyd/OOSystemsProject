#include "Enemy.h"
#include <cstdlib>
#include <iostream>

int Enemy::getCurrentHealth()
{
	return currentHealth;
}

void Enemy::setCurrentHealth(int amount)
{
	currentHealth = amount;
}

bool Enemy::getCombatMove()
{
	srand((unsigned)time(0)); //Used to randomise the attack pattern each time
	int randomNumber = rand()%2;

	if (randomNumber == 0)
	{
		bisAttacking = true;
		bisDefending = false;
		return true;
	}
	else if (randomNumber == 1)
	{
		bisDefending = true;
		bisAttacking = false;
		return false;
	}
}

void Enemy::Defend()
{
	if (bisDefending && !bisAttacking)
	{
		if (currentHealth < MAX_HEALTH)
		{
			std::cout << "The enemy defends and recovers 1hp! \n";
			setCurrentHealth(currentHealth + 1);
		}
		else
		{
			std::cout << "The enemy defends but is already at max hp! \n";
		}
	}
}

bool Enemy::Attack(int attackHitChance)
{
	if (bisAttacking && !bisDefending)
	{
		srand((unsigned)time(0)); //Used to randomise the attack pattern each time
		int attackHitChance = rand() % 2;
		if (attackHitChance == 0)
		{
			std::cout << "The enemy attacks and hits! \n";
			return true;
		}
		else
		{
			std::cout << "The enemy attacks and misses! \n";
			return false;
		}
	}
}

bool Enemy::CheckDead()
{
	if (currentHealth <= 0)
	{
		bIsDead = true;
	}
	else
	{
		bIsDead = false;
	}
	return bIsDead;
}
