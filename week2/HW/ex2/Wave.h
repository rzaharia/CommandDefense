#pragma once

class Wave
{
  private:
    char* name;
    int numberOfEnemies;
    int startingHealth;
    float moneyPerEnemy;

  public:
    char* GetPtr();

    void SetName(const char* otherName);
    const char* GetName() const;

    void SetNumberOfEnemies(int numberOfEnemies);
    int GetNumberOfEnemies() const;
};