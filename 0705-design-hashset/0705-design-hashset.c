#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    bool *data;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet *obj = malloc(sizeof(MyHashSet));
    obj->data = calloc(1000001, sizeof(bool));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->data[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->data[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->data[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->data);
    free(obj);
}