#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int count[3];
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* obj = malloc(sizeof(ParkingSystem));

    obj->count[0] = big;
    obj->count[1] = medium;
    obj->count[2] = small;

    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    int index = carType - 1;

    if (obj->count[index] == 0)
        return false;

    obj->count[index]--;

    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}