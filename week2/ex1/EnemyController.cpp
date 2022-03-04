#include "EnemyController.h"
#include<iostream>

using namespace std;


void EnemyController::Init(int maximumEnemies, int step, Point initialLocation)
{  //initialize the array of enemies 
    this->enemies_spawned = 0;
     enemies = new Enemy[maximumEnemies];
     
    //looop through the array and init all of them 
     for (int i = 0; i < maximumEnemies; i++)
     {
         //initial location and init health
         enemies[i].Init(initialLocation, ENEMY_HEALTH);
         this->move_speed = step; 

     }


}
/// <summary>
/// Delete all the enemies 
/// </summary>
void EnemyController::Uninit()
{
    delete enemies;

}
/// <summary>
/// Move all the enemies by a given direction 
/// </summary>
void EnemyController::Move(EnemyDirection direction )
{
    //iterate through all the enemies and move every one of them 

    if (!enemies_spawned) return; 
    else {

        for (int i = 0; i < enemies_spawned; i++)
        {
            enemies[i].Move(direction , this->move_speed);

        }

    }

}
/// <summary>
/// Damage all the enemies 
/// </summary>
void EnemyController::DamageAll()
{
    for (int i = 0; i < enemies_spawned; i++)
    {
        enemies[i].Shoot(i + 1);
    }

}
/// <summary>
/// Count the enemies that were killed 
/// </summary>
/// <returns></returns>
int EnemyController::CountKilledEnemies()
{

    unsigned int count = 0; 
    for (int i = 0; i < enemies_spawned; i++)
    {
        if (enemies[i].IsDead()) count++;
    }

    return count;
}
/// <summary>
/// Checks wether an enemy can be spawned or not 
/// </summary>
/// <returns></returns>
bool EnemyController::SpawnEnemy()
{
    
    if (enemies_spawned >= MAX_ENEMIES) return false; 
    
    //otherwise spawn the enemy 
    cout << "Enemy number" << enemies_spawned + 1 << " " << "spawned! " << endl;
    enemies_spawned++;
}

void EnemyController::DamageAllBy(int damage)
{


    for (int i = 0; i < enemies_spawned; i++)
        enemies[i].Shoot(damage);

}
void EnemyController::PrintHealth()
{
    cout << endl;
    for (int i = 0; i < enemies_spawned; i++)
        cout << "Health of enemy no" << ' ' << i << " is "<< enemies[i].get_Health() << endl;
}