#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 200005

typedef struct {
    int userId;
    int taskId;
    int priority;
    int valid;
} Task;

typedef struct {
    Task *heap[MAX_TASKS];
    int size;
    Task *taskMap[MAX_TASKS];
} TaskManager;

// comparator
int cmp(Task *a, Task *b) {
    if (a->priority != b->priority) return a->priority > b->priority;
    return a->taskId > b->taskId;
}

void swap(Task **a, Task **b) {
    Task *tmp = *a; *a = *b; *b = tmp;
}

void heapifyUp(TaskManager *tm, int idx) {
    while (idx > 1 && cmp(tm->heap[idx], tm->heap[idx/2])) {
        swap(&tm->heap[idx], &tm->heap[idx/2]);
        idx /= 2;
    }
}

void heapifyDown(TaskManager *tm, int idx) {
    while (1) {
        int largest = idx;
        int l = idx*2, r = idx*2+1;
        if (l <= tm->size && cmp(tm->heap[l], tm->heap[largest])) largest = l;
        if (r <= tm->size && cmp(tm->heap[r], tm->heap[largest])) largest = r;
        if (largest == idx) break;
        swap(&tm->heap[idx], &tm->heap[largest]);
        idx = largest;
    }
}

TaskManager* taskManagerCreate(int** tasks, int tasksSize, int* tasksColSize) {
    TaskManager *tm = (TaskManager*)malloc(sizeof(TaskManager));
    tm->size = 0;
    memset(tm->taskMap, 0, sizeof(tm->taskMap));
    for (int i = 0; i < tasksSize; i++) {
        Task *t = (Task*)malloc(sizeof(Task));
        t->userId = tasks[i][0];
        t->taskId = tasks[i][1];
        t->priority = tasks[i][2];
        t->valid = 1;
        tm->taskMap[t->taskId] = t;
        tm->heap[++tm->size] = t;
        heapifyUp(tm, tm->size);
    }
    return tm;
}

void taskManagerAdd(TaskManager* tm, int userId, int taskId, int priority) {
    Task *t = (Task*)malloc(sizeof(Task));
    t->userId = userId; t->taskId = taskId; t->priority = priority; t->valid = 1;
    tm->taskMap[taskId] = t;
    tm->heap[++tm->size] = t;
    heapifyUp(tm, tm->size);
}

void taskManagerEdit(TaskManager* tm, int taskId, int newPriority) {
    Task *t = tm->taskMap[taskId];
    if (!t) return;
    t->valid = 0;
    Task *newT = (Task*)malloc(sizeof(Task));
    newT->userId = t->userId; newT->taskId = taskId; newT->priority = newPriority; newT->valid = 1;
    tm->taskMap[taskId] = newT;
    tm->heap[++tm->size] = newT;
    heapifyUp(tm, tm->size);
}

void taskManagerRmv(TaskManager* tm, int taskId) {
    Task *t = tm->taskMap[taskId];
    if (!t) return;
    t->valid = 0;
    tm->taskMap[taskId] = NULL;
}

int taskManagerExecTop(TaskManager* tm) {
    while (tm->size > 0) {
        Task *top = tm->heap[1];
        if (!top->valid) {
            tm->heap[1] = tm->heap[tm->size--];
            heapifyDown(tm, 1);
            continue;
        }
        int userId = top->userId;
        top->valid = 0;
        tm->taskMap[top->taskId] = NULL;
        tm->heap[1] = tm->heap[tm->size--];
        heapifyDown(tm, 1);
        return userId;
    }
    return -1;
}

void taskManagerFree(TaskManager* tm) {
    free(tm);
}
