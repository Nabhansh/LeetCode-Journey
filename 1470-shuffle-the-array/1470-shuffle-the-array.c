int* shuffle(int* s, int numsSize, int n, int* r){
   int i,*a,k=0;
    a=(int *)malloc(2*n*sizeof(int));
    for(i=0;i<2*n;i=i+2){
        a[i]=s[k];
        a[i+1]=s[n+k];
        k++;
        
    }
   
    *r=2*n;
    return a;
}