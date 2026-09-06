int maximumGap(char* skill, char* station) {
    int nn=strlen(skill);
    int mm=strlen(station);
    if(nn<=1)
        return 0;
    int left_side[nn], right_side[nn];
    int j=0;
    for(int i=0; i<nn; i++){
        while(station[j]!=skill[i])
            j++;
        left_side[i]=j++;
    }
    j=mm-1;
    for(int i=nn-1; i>=0; i--){
        while(station[j]!=skill[i])
            j--;
        right_side[i]=j--;
    }
    int final=0;
    for(int i=0; i<nn-1; i++){
        int space=right_side[i+1]-left_side[i];
        if(space>final)
            final=space;
    }
    return final;
}