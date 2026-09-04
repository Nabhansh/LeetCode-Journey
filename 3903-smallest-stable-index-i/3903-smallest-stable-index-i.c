int firstStableIndex(int* nums, int numsSize, int k) {
    int n=numsSize;
    int i,j,max,min;
    for(i=0;i<n;i++){
        max=min=nums[i];
        for(j=0;j<=i;j++){
            if(nums[j]>max)
            max=nums[j];
        }
        for(j=i;j<n;j++){
            if(nums[j]<min)
            min=nums[j];
        }
        int s=max-min;
    if(s<=k)
    return i;
    }
    return -1;  
}