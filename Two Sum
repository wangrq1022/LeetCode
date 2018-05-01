/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *p,i,j;
  
    p = malloc(2*sizeof(int));
       
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){          
            if(target==nums[i]+nums[j]){
                p[0] = i;
                p[1] = j;
                return p;
            }         
        }       
    }    
       
    return NULL;
}
