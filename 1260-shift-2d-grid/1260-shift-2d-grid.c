int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = gridSize ;
    int d = (gridSize)*(*gridColSize) ;
    k = k%(d) ;
    int *temp = malloc(k*sizeof(int)) ;
    *returnColumnSizes = (int*)malloc(gridSize*sizeof(int));
    int i = 0 ;
    while(i < gridSize){
        (*returnColumnSizes)[i] = *gridColSize;
        i++ ;
    }
    if(k==0){
        return grid ;
    }
    i = 0 ;
    while(i < k){
        temp[i] = grid[i/(*gridColSize)][i%(*gridColSize)] ;
        i++ ;
    }
    i = 0 ;
    while(i < d){
        int tem = grid[((i + k)/(*gridColSize))%gridSize][(i + k)%(*gridColSize)] ;
        grid[((i + k)/(*gridColSize))%gridSize][(i + k)%(*gridColSize)] = *(temp + (i + k)%(k)) ;
        *(temp + (i + k)%(k)) = tem ; 
        i++  ;
    }    
   int **ans = malloc(gridSize*sizeof(int*)) ;
   i = 0 ;
   while(i < gridSize){
    *(ans + i) = malloc((*gridColSize)*sizeof(int)) ;
    i++ ;
   }
   i = 0 ;
   while(i < gridSize){
    int j = 0 ;
    while(j < *gridColSize){ 
        *(*(ans + i) + j) = *(*(grid + i)+ j) ;
        j++ ;
    }
    i++ ;
   }
   return ans ;
}