/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
   *returnSize=numsSize;
    int p=0;
   int* arr;
   arr=(int *)malloc(sizeof(int)*numsSize);
   for(int i=0;i<numsSize;i++){
       if(nums[i]<pivot)
       arr[p++]=nums[i];
   } 
   for(int i=0;i<numsSize;i++){
       if(nums[i]==pivot)
       arr[p++]=nums[i];
   }
    for(int i=0;i<numsSize;i++){
       if(nums[i]>pivot)
       arr[p++]=nums[i];
   }
    return arr;
}