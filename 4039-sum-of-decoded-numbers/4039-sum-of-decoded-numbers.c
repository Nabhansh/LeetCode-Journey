int sumDecoded(long long* nums, int numsSize) {
    const long long MODULUS=1000000007;
    long long final_answer=0;
    for(int i=0; i<numsSize; i++){
        int widthhs=nums[i]%10;
        long long dd=nums[i]/10;
        long long temporary=dd;
        int digitszz=0;
        while(temporary>0){
            digitszz++;
            temporary/=10;
        }
        long long divisior=1;
        for(int j=0; j<digitszz-widthhs; j++)
            divisior*=10;
        long long xx=dd/divisior;
        long long yy=dd%divisior;
        long long final_result=1;
        while(yy>0){
            if(yy%2==1)
                final_result=(final_result*xx)%MODULUS;
            xx=(xx*xx)%MODULUS;
            yy/=2;
        }
        final_answer=(final_answer + final_result)%MODULUS;
    }
    return (int)final_answer;
}