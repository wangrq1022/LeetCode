/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int num;
    int sub;
}table;

int cmp( const void *a , const void *b ){
    return ((table *)a)->num - ((table *)b)->num; 
}

table* search(table* pTable, int Size, int Target){
    int m = Size>>1;
    
    if(pTable[m].num==Target)
        return &pTable[m];
    if(!m)
        return NULL;

    if(pTable[m].num>Target)
        return search(pTable, m, Target);
    else
        return search(pTable+m+1, Size-m-1, Target);
}

int* twoSum(int* nums, int numsSize, int target) {
    int   *p, i=0;   
    table *pTable, *pFind, *pWalk;
    
    pTable = malloc(numsSize*sizeof(table));
    for(pWalk=pTable; pWalk<&pTable[numsSize]; pWalk++){
        pWalk->num = nums[i];  
        pWalk->sub = i++;
    }    
    qsort(pTable,numsSize,sizeof(table),cmp);
    
    for(pWalk=pTable; pWalk<&pTable[numsSize]; pWalk++){
        if(pFind=search(pTable, numsSize, target-pWalk->num))
            if(pFind->sub!=pWalk->sub)
                break;
    }
    
    p = malloc(2*sizeof(int));
    p[0] = pWalk->sub;
    p[1] = pFind->sub;

    free(pTable);
    return p;
}
