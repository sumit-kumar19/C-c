#include <stdio.h>
#include<stdlib.h>

int maxi(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}

void countsort(int arr[],int n,int pos){
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    int out[n];
    for(int i=n-1;i>=0;i--){
        out[--count[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++)
    arr[i]=out[i];
}

void radixsort(int arr[],int n){
    int k=maxi(arr,n);
    for(int pos=1;k/pos>0;pos*=10){
        countsort(arr,n,pos);
    }
}

void display(int arr[], int n){
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array element: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    radixsort(arr,n);
    display(arr,n);
    return 0;
}
