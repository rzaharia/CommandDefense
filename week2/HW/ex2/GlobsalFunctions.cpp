#include "GlobsalFunctions.h"

int CompareWavesNumberOfEnemies(const Wave& w1, const Wave& w2)
{
    if (w1.GetNumberOfEnemies() == w2.GetNumberOfEnemies())
        return 0;
    if (w1.GetNumberOfEnemies() > w2.GetNumberOfEnemies())
        return 1;
    return -1;
}
