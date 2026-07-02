int removeAlmostEqualCharacters(char* word) {
    int count = 0;
    while( *(word+1) != '\0' ){
        if(*word==*(word+1) || (*word-*(word+1)) == 1 || (*word-*(word+1)) == -1 ){
            count++;
            if(*(word+2) == '\0') break;
            word+=2;
            continue;
        }
        word++;
    }
    return count;
}