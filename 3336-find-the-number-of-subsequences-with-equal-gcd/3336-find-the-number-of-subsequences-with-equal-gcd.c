int cnt=0,ways[201][201],temp_ways[201][201],mod=((int)1e9+7);// n
int modadd(int a,int b){
    a += b;
    if(a>=mod) a-=mod;
    return a;
}
int _max(int a,int b){
    return ((a>=b)?(a):(b));
}
int gcd(int a,int b){
    return ((b>0)?(gcd(b,a%b)):(a));
}
int subsequencePairCount(int* nums, int numsSize) {
    memset(ways,0,sizeof(ways));memset(temp_ways,0,sizeof(temp_ways));
    cnt = 0;
    int i=0,n=numsSize,gcd1,gcd2,maxi=nums[0];
    for(i=1;i<n;i++){
        maxi = _max(maxi,nums[i]);
    }
    ways[0][0] = 1;
    for(i=n-1;i>=0;i--){
        for(int g1=0;g1<=maxi;g1++){            
            int G1 = gcd(nums[i],g1);
            for(int g2=0;g2<=maxi;g2++){
                int G2 = gcd(nums[i],g2);
                // add current ele to set one 
                temp_ways[G1][g2] = modadd(temp_ways[G1][g2] ,ways[g1][g2]);
                // add current ele to set two 
                temp_ways[g1][G2] = modadd(temp_ways[g1][G2] ,ways[g1][g2]);
                // skip adding current to both the sets 
                temp_ways[g1][g2] = modadd(temp_ways[g1][g2],ways[g1][g2]);
            }
        }       
        memcpy(ways,temp_ways,201*201*sizeof(int));
        memset(temp_ways,0,201*201*sizeof(int));
    }
    cnt = 0;
    for(gcd1=1;gcd1<=maxi;gcd1++){       
        cnt = modadd(cnt,ways[gcd1][gcd1]);
    }
    return cnt;
}