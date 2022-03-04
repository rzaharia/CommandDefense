#pragma once

#include "EnemiesStructures.h"
#include "Enemy.h"
//class Enemy; //forward declaration nu stiu de ce nu merge cu class enemy :)

#define ENEMY_HEALTH 10
#define MAX_ENEMIES 50


class EnemyController : public Enemy
{
private:
    //Place here other required variables
    Enemy* enemies;
    int stepSize;
    Point startingLocation;
    int enemies_spawned;
    int move_speed;

public:
    void Init(int maximumEnemies, int step, Point initialLocation); // set maxEnemies and stepSize and allocated enemies and do the rest of initialization
 
    void Uninit();//delete allocated resources

    void Move(EnemyDirection direction);//move all spawned enemies (current enemies)
    void DamageAll(); // goes through every enemy and shoots them with the damage value (index of the element + 1)
    int CountKilledEnemies(); //returns the number of enemeies which are dead
    bool SpawnEnemy(); //if it can add the new enemy with ENEMY_HEALTH health value returns true, otherwise false
    void DamageAllBy( int damage  ); // extra method to damage all the enemies by a given value 
    void PrintHealth();//extra  helper method to print the health of the enemies 
};