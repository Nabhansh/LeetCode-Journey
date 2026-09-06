#include<stdlib.h>
int comparabless(const void *yy, const void *zz){
    return (*(int *)yy-*(int *)zz);
}
int** findDisappearedNumbers(int* nums, int numsSize, int lower, int upper, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), comparabless);
    int **final_answer=malloc((numsSize+1)*sizeof(int *));
    *returnColumnSizes=malloc((numsSize+1)*sizeof(int));
    int counter=0, nextt=lower;
    for(int i=0; i<numsSize && nextt<=upper; i++){
        if(nums[i]<nextt)
            continue;
        if(nums[i]>upper)
            break;
        if(nums[i]>nextt){
            final_answer[counter]=malloc(2*sizeof(int));
            final_answer[counter][0]=nextt;
            final_answer[counter][1]=nums[i]-1;
            (*returnColumnSizes)[counter++]=2;
        }
        nextt=nums[i]+1;
    }
        if(nextt<=upper){
            final_answer[counter]=malloc(2*sizeof(int));
            final_answer[counter][0]=nextt;
            final_answer[counter][1]=upper;
            (*returnColumnSizes)[counter++]=2;
        }
    *returnSize=counter;
    return final_answer;
}