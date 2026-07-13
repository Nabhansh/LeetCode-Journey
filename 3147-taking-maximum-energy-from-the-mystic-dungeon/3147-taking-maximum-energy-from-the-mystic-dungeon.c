#include <limits.h>

int maximumEnergy(int* energy, int energySize, int k) {
    int answer = INT_MIN;

    for (int i = energySize - 1; i >= 0; i--) {
        if (i + k < energySize) {
            energy[i] += energy[i + k];
        }

        if (energy[i] > answer) {
            answer = energy[i];
        }
    }

    return answer;
}