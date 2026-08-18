
long long countDistinct(long long n) {
    long long cur = n % 10;
    long long firstRoundSum = 0;
    long long firstRound = 1;
    long long otherRound = 1;
    for(long long i = 10; i <= n ; i = i * 10){
       firstRound = firstRound * 9;
       firstRoundSum += firstRound;
       otherRound = otherRound * 9;
       long long temp = n % (i *10); // get current digit
       long long temp2 = temp / i; // get current digit
       if(0 == temp2){
        cur = 0;
       }
       else{
        cur += ((temp2 - 1) * otherRound); // if cur digit is 1 && is not leading digit we only have to count up lower digit >> 0X not exit , 1X valid count = X , YX valid count = (Y-1)*9 + X   
       }
       if ((n / (i * 10)) < 1){ // check cur digit is leading digit,avoid recount 1~k-1 numbers
        cur += firstRoundSum;
       }
    }
    return cur;
}