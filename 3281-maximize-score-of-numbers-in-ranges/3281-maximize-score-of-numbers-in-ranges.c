#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

bool check(int* start,int n,int d,long long gap){
    long long last=start[0];

    for(int i=1;i<n;i++){
        long long cur=last+gap;
        if(cur<start[i]) cur=start[i];
        if(cur> (long long)start[i]+d)
            return false;
        last=cur;
    }
    return true;
}

int maxPossibleScore(int* start,int startSize,int d){
    qsort(start,startSize,sizeof(int),cmp);

    long long lo=0,hi=2000000000LL;

    while(lo<hi){
        long long mid=(lo+hi+1)/2;
        if(check(start,startSize,d,mid))
            lo=mid;
        else
            hi=mid-1;
    }

    return (int)lo;
}