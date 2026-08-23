#include <stdlib.h>

typedef struct {
    int riders[1005];
    int drivers[1005];
    int riderFront;
    int riderBack;
    int driverFront;
    int driverBack;
    int active[1001];
} RideSharingSystem;

RideSharingSystem* rideSharingSystemCreate() {
    RideSharingSystem* obj = malloc(sizeof(RideSharingSystem));
    obj->riderFront = 0;
    obj->riderBack = 0;
    obj->driverFront = 0;
    obj->driverBack = 0;

    for (int i = 0; i <= 1000; i++)
        obj->active[i] = 0;

    return obj;
}

void rideSharingSystemAddRider(RideSharingSystem* obj, int riderId) {
    obj->riders[obj->riderBack++] = riderId;
    obj->active[riderId] = 1;
}

void rideSharingSystemAddDriver(RideSharingSystem* obj, int driverId) {
    obj->drivers[obj->driverBack++] = driverId;
}

int* rideSharingSystemMatchDriverWithRider(RideSharingSystem* obj, int* retSize) {
    int* result = malloc(2 * sizeof(int));

    while (obj->riderFront < obj->riderBack &&
           !obj->active[obj->riders[obj->riderFront]]) {
        obj->riderFront++;
    }

    if (obj->riderFront >= obj->riderBack ||
        obj->driverFront >= obj->driverBack) {
        result[0] = -1;
        result[1] = -1;
        *retSize = 2;
        return result;
    }

    result[0] = obj->drivers[obj->driverFront++];
    result[1] = obj->riders[obj->riderFront];

    obj->active[result[1]] = 0;
    obj->riderFront++;

    *retSize = 2;
    return result;
}

void rideSharingSystemCancelRider(RideSharingSystem* obj, int riderId) {
    obj->active[riderId] = 0;
}

void rideSharingSystemFree(RideSharingSystem* obj) {
    free(obj);
}