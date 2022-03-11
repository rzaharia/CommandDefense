#include "EnemyController.h"
#include "Enemy.h" // to actualy use the field Enemy declared in the header by forward declaration, we use the field here

void EnemyController::Init(int maximumEnemies, int step, Point initialLocation)
{
    enemies         = new Enemy[maximumEnemies];
    stepSize        = step;
    startinLocation = initialLocation;
    currentCount    = 0;
    maxEnemies      = maximumEnemies;
}

void EnemyController::Uninit()
{
    delete[] enemies;
}

void EnemyController::Move()
{
    for (int i = 0; i < currentCount; i++)
        enemies[i].Move(EnemyDirection::RightDirection, stepSize);
}

void EnemyController::DamageAll()
{
    for (int i = 0; i < currentCount; i++)
        enemies[i].Shoot(i + 1);
}

int EnemyController::CountKilledEnemies()
{
    int count = 0;
    for (int i = 0; i < currentCount; i++)
        if (enemies[i].IsDead())
            count++;
    return count;
}

bool EnemyController::SpawnEnemy()
{
    if (currentCount >= maxEnemies)
        return false;
    enemies[currentCount].Init(startinLocation, ENEMY_HEALTH);
    currentCount++;
    return true;
}
