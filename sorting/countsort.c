#include<stdio.h>
#include<stdlib.h>

int max(int *arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k=max(arr,n);
    int count[k+1];
    for(int i=0;i<=k;i++){
        count[i]=0;
    }

    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=0;i<=k;i++){
        printf("%d \t",count[i]);
    }

    for(int i=1;i<=k;i++){
        count[i]=count[i]+count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++){
        printf("<%d>",output[i]);
    }



}
