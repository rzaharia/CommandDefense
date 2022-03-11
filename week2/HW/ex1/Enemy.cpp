#include "Enemy.h"

void Enemy::Init(Point intitialLocation, int initialHealh)
{
    this->location = intitialLocation;
    this->health   = initialHealh;
}

void Enemy::Move(EnemyDirection direction, int step)
{
    switch (direction)
    {
    case EnemyDirection::UpDirection:
        location.y -= step;
        break;
    case EnemyDirection::DownDirection:
        location.y += step;
        break;
    case EnemyDirection::LeftDirection:
        location.x -= step;
        break;
    case EnemyDirection::RightDirection:
        location.x += step;
        break;
    default:
        break;
    }
}

bool Enemy::IsDead() const
{
    return health <= 0;
}

void Enemy::Shoot(int damage)
{
    health -= damage;
}
