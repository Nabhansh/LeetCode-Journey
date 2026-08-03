#define MAX_USERS 100
typedef struct {
    int timestamp;
    int type; 
    int originalIndex;
} EventMeta;
int compareEvents(const void* a, const void* b) {
    const EventMeta* ea = (const EventMeta*)a;
    const EventMeta* eb = (const EventMeta*)b;

    if (ea->timestamp != eb->timestamp) {
        return ea->timestamp - eb->timestamp;
    }

    return ea->type - eb->type;
}

int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize) {
    *returnSize = numberOfUsers;

    int* dp = (int*)calloc(numberOfUsers, sizeof(int));  
    int* onl = (int*)calloc(numberOfUsers, sizeof(int)); 

    EventMeta* metas = (EventMeta*)malloc(eventsSize * sizeof(EventMeta));
    for (int i = 0; i < eventsSize; i++) {
        metas[i].timestamp = atoi(events[i][1]);
        metas[i].originalIndex = i;

        if (strcmp(events[i][0], "OFFLINE") == 0) {
            metas[i].type = 0;
        } else {
            metas[i].type = 1;
        }
    }
    qsort(metas, eventsSize, sizeof(EventMeta), compareEvents);
    for (int i = 0; i < eventsSize; i++) {
        int idx = metas[i].originalIndex;
        int ts = metas[i].timestamp;

        if (metas[i].type == 0) { 
            int userId = atoi(events[idx][2]); 
            onl[userId] = ts + 60;  
        } else { 
            char* content = events[idx][2];

            if (strcmp(content, "ALL") == 0) {
                for (int u = 0; u < numberOfUsers; u++) {
                    dp[u]++; 
                }
            } else if (strcmp(content, "HERE") == 0) { 
                for (int u = 0; u < numberOfUsers; u++) {
                    if (onl[u] <= ts) { 
                        dp[u]++;  
                    }
                }
            } else { 
                int j = 0;
                while (content[j] != '\0') {
                    if (content[j] == 'i' && content[j + 1] == 'd') {  
                        j += 2;
                        int idVal = 0;

                        while (content[j] >= '0' && content[j] <= '9') {  
                            idVal = idVal * 10 + (content[j] - '0');
                            j++;
                        }
                        dp[idVal]++;  
                    } else {
                        j++;
                    }
                }
            }
        }
    }

    free(metas);
    free(onl);
    return dp;  
}