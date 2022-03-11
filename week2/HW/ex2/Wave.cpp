#include "Wave.h"
#include <cstring>

char* Wave::GetPtr()
{
    return name;
}

void Wave::SetName(const char* otherName)
{
    int lenght = strlen(otherName);
    name       = new char[lenght + 1];
    strcpy_s(name, lenght + 1, otherName);
}

const char* Wave::GetName() const
{
    return name;
}

void Wave::SetNumberOfEnemies(int numberOfEnemies)
{
    if (numberOfEnemies > 0)
        this->numberOfEnemies = numberOfEnemies;
}

int Wave::GetNumberOfEnemies() const
{
    return numberOfEnemies;
}
