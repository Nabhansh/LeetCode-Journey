class ParkingSystem {
private:
    int spaces[4];

public:
    ParkingSystem(int big, int medium, int small) {
        spaces[1] = big;
        spaces[2] = medium;
        spaces[3] = small;
    }

    bool addCar(int carType) {
        if (spaces[carType] > 0) {
            spaces[carType]--;
            return true;
        }

        return false;
    }
};