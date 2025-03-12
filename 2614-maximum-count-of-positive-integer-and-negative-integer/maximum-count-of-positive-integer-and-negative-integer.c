int maximumCount(int* nums, int numsSize) {
 int p=0,n=0,max=0;
 for(int i=0;i<numsSize;i++){
     if(nums[i]>0)
     p++;
     if(nums[i]<0)
     n++;
 }   
 if(p>=n){
     max=p;
 }
 if(p<=n){
     max=n;
 }
 return max;
}