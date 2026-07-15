#include <limits.h>

long long maximumPoints(int* enemyEnergies, int enemyEnergiesSize,
                        int currentEnergy) {
    int minEnergy = INT_MAX;
    long long totalEnergy = currentEnergy;

    for (int i = 0; i < enemyEnergiesSize; i++) {
        if (enemyEnergies[i] < minEnergy) {
            minEnergy = enemyEnergies[i];
        }

        totalEnergy += enemyEnergies[i];
    }

    if (currentEnergy < minEnergy) {
        return 0;
    }

    return (totalEnergy - minEnergy) / minEnergy;
}