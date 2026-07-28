char* smallestPalindrome(char* s) {
    int *freq = calloc(26,sizeof(int)) ;
    int n = strlen(s) ;
    for(int i = 0 ; i < n ; i++){
        freq[s[i] - 'a'] = freq[s[i] - 'a'] + 1 ;
    }
    char *ans = malloc((n + 1)*sizeof(char)) ;
    *(ans + n) = '\0' ;
    int index = 0 ;
    if(n == 1){
        int i = 0 ;
        while(*(freq + i) == 0){
            i++ ;
        }
        *(ans + n/2) = 'a' + i ;
        return ans ;
    }
    for(int i = 0 ; i < 26 ; i++){
        while(*(freq + i) > 1){
            *(ans + index) = 'a' + i ;
            *(ans + n - 1 - index) = 'a' + i ;
            *(freq + i) = *(freq + i) - 2 ;
            index++ ;
        }
    }
    if(n%2 != 0){
        int i = 0 ;
        while(*(freq + i) == 0){
            i++ ;
        }
        *(ans + n/2) = 'a' + i ;
    }
    free(freq) ;
    return ans ;
}