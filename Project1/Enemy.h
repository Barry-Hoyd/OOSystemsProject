#pragma once
class Enemy
{
public:
	int currentHealth = 0;
	int MAX_HEALTH =0;
	bool bCurrentlyHealing = false;
	int armour =0;
	int damage = 0;
	int attackHitChance=0;
	bool bCombatMove=0;
	bool bisAttacking = false;
	bool bisDefending = false;

	int getCurrentHealth();

	void setCurrentHealth(int amount);

	void getCombatMove();

	void Defend();

	void Attack(int attackHitChance);
};

class GoblinEnemy : public Enemy
{
public:
	GoblinEnemy()
	{
		currentHealth = 10;
		MAX_HEALTH = 10;
		armour = 0;
		damage = 2;
		attackHitChance = 1; // 1 so there is a 1/2 chance of attacking
	}
};

class OgerEnemy : public Enemy
{
public:
	OgerEnemy()
	{
		currentHealth = 15;
		MAX_HEALTH = 15;
		armour = 2;
		damage = 3;
		attackHitChance = 2; // 2 so there is a 1/3 chance of attacking
	}
};

class CyclopsEnemy : public Enemy
{
public:
	CyclopsEnemy()
	{
		currentHealth = 5;
		MAX_HEALTH = 5;
		armour = 1;
		damage = 3;
		attackHitChance = 0; // 0 because when random int is generated it will always attack
	}
};
