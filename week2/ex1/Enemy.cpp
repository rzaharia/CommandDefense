#include "Enemy.h"
#include <iostream>
#include "EnemiesStructures.h"

using namespace std;



/// <summary>
/// Set the initial location and initial health of the enemy 
/// </summary>
/// <param name="initalLocation"></param>
/// <param name="initialHealth"></param>
void Enemy::Init(Point initalLocation , int initialHealth)
{
	this->health = initialHealth;
	this->location = initalLocation;

 }

//GET and SETTER methods 

int Enemy::get_Health()
{
	return this->health;
}

void Enemy::set_health(int new_val )
{


	this->health = new_val;
}



/// <summary>
/// Function to move the enemy in the 'dir' direction by 'step'
/// </summary>
/// <param name="dir"></param>
/// <param name="step"></param>
void Enemy::Move(EnemyDirection dir , int step)
{

	switch (dir)
	{

	case EnemyDirection::UpDirection:
		//decrease y by step 
		this->location.y -= step;
		break;
	case EnemyDirection::DownDirection:
		//increase y by step
		this->location.y += step;
		break;
	case EnemyDirection::LeftDirection:
		//decrease x by step
		this->location.x -= step;
		break;
	case EnemyDirection::RightDirection:
		this->location.x += step;
		break;


	default: cout << "Parameter dir not valid !/n";


	}

}

/// <summary>
/// Checks if the enemy is dead or alive 
/// </summary>
/// <returns></returns>
bool Enemy::IsDead()
{

	return this->health > 0 ? false  : true;

}

//Every time function is called the health is decreased by 'damage'"
void Enemy::Shoot(int damage)
{
	this->health -= damage;

}
