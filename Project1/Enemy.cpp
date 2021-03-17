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

void Enemy::getCombatMove()
{
	srand((unsigned)time(0)); //Used to randomise the attack pattern each time
	int randomNumber = rand()%2;

	if (randomNumber == 0)
	{
		bisAttacking = true;
		bisDefending = false;
		std::cout << "Attack" << "\n";
	}
	else if (randomNumber == 1)
	{
		bisDefending = true;
		bisAttacking = false;
		std::cout << "Defend" << "\n";
	}
}

void Enemy::Defend()
{
	if (bisDefending && bisAttacking == false)
	{
		setCurrentHealth(currentHealth++);
	}
}

void Enemy::Attack(int attackHitChance)
{
	if (bisAttacking && bisDefending == false)
	{
		srand((unsigned)time(0)); //Used to randomise the attack pattern each time
		//int attackChance = rand() % attackChance;
	}
}
