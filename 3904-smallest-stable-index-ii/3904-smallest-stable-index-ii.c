int firstStableIndex(int* nums, int numsSize, int k) {
    int mins[numsSize], max, i;

    mins[numsSize-1]=nums[numsSize-1];
    for(i=numsSize-2; i>=0; i--)
    { mins[i]=mins[i+1]<=nums[i]?mins[i+1]:nums[i]; }

    for(i=0,max=nums[0]; i<numsSize; i++) {
        max=max>=nums[i]?max:nums[i];
        if(max-mins[i]<=k){ return i; }
    }

    return -1;
}