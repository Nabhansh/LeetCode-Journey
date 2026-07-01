#include <stdlib.h>

typedef struct {
    int *data;
} MyHashMap;

MyHashMap* myHashMapCreate() {
    MyHashMap *obj = malloc(sizeof(MyHashMap));
    obj->data = malloc(sizeof(int) * 1000001);

    for (int i = 0; i <= 1000000; i++)
        obj->data[i] = -1;

    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->data[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->data[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->data[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->data);
    free(obj);
}