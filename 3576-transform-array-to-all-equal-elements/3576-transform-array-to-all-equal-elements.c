bool canMakeEqual(int* nums, int numsSize, int k) {
    // all 1
    int k1=0;
    int sign = 1;
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]*sign!=1){
            sign = -1;
            k1++;
        }else{
            sign=1;
        }
    }
    if(nums[numsSize-1]*sign!=1) k1=k+1;
    // all -1
    int k2=0;
    sign = 1;
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]*sign!=-1){
            k2++;
            sign = -1;
        }else{
            sign = 1;
        }
    }
    if(nums[numsSize-1]*sign!=-1) k2=k+1;
    return k2<=k||k1<=k?true:false;
}