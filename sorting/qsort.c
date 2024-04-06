#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int arr[],int i,int j){
  int temp=0;
  temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}
int partition(int arr[],int l,int h){
 int i=l-1;
 int j=l;
 int piv=arr[h];
 for(j=l;j<h;j++){
     if(arr[j]<piv){
         i++;
         swap(arr,i,j);
     }
 }
 swap(arr,i+1,j);

 return i+1;
}

void quicksort(int arr[],int l,int h){
    if(l>=h)
    return ;
    int pi=partition(arr,l,h);
    quicksort(arr,l,pi-1);
    quicksort(arr,pi+1,h);
}

void display(int arr[], int n){
    int i;
    for (i=0; i < n; i++)
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
int l=0,h=n-1;
quicksort(arr,l,h);
display( arr, n);
    return 0;
}
