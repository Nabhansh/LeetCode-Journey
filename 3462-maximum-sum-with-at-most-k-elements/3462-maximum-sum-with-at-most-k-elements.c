int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); // Sort in descending order
}


int max(int a, int b) {
    return (a > b) ? a : b;
}

long long maxSum(int** grid, int gridSize, int* gridColSize, int* limits, int limitsSize, int k) {
    
    //DP ??
    
    // row sorting ?
    int i=0,j=0;
    int* sortedRow = (int*)malloc(sizeof(int) * gridColSize[0]);
    int* out_arr=(int*)malloc(sizeof(int)*500*500);

    memset(out_arr,0,500*500);
    
    // dp array : [row+1][elements taken +1]
    //int** dp_array=(int**)malloc((gridSize+1)*sizeof(int*));

    int limit_num=0;
    for(i=0;i<gridSize;i++)
    {
        if(limits[i]<=0) 
        {   
            continue;
        }
        memcpy(sortedRow,grid[i],sizeof(int)*gridColSize[i]);
        qsort(sortedRow,gridColSize[i],sizeof(int),compare);

        for(j=0;j<limits[i];j++)
        {
            out_arr[limit_num++]=sortedRow[j];
        }

    }
    // sorting out_arr
    qsort(out_arr,limit_num,sizeof(int),compare);
    long long result=0;
    for(i=0;i<k;i++)
    {
        result+=out_arr[i];
    }
    return result;
    
}