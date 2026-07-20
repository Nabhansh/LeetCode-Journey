typedef long long ll;

ll max(ll a, ll b) {
    return a > b ? a : b;
}

long long maxEnergyBoost(int* energyDrinkA, int energyDrinkASize,
                         int* energyDrinkB, int energyDrinkBSize) {
    ll dpA = 0;
    ll dpB = 0;

    for (int i = 0; i < energyDrinkASize; i++) {
        ll newA = max(dpA + energyDrinkA[i], dpB);
        ll newB = max(dpB + energyDrinkB[i], dpA);

        dpA = newA;
        dpB = newB;
    }

    return max(dpA, dpB);
}