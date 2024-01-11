// #include <stdio.h>
// #include<stdlib.h>
//
// void mergearr(int a[],int f,int mid,int l){
//     if(f==l)
//     return;
//     int *c;
//     c=(int* )malloc((l+1)*sizeof(int));
//     int i=0,j=mid+1,k=0;
//     while((i<=mid&&j<=l)){
//         if(a[i]<a[j])
//         c[k++]=a[i++];
//         else
//         c[k++]=a[j++];
//     }
//     if(i<=mid)
//     for(;i<=mid;i++){
//         c[k++]=a[i];
//     }
//     else{
//         for(;j<=l;j++){
//             c[k++]=a[j];
//         }
//     }
//     for(int i=0;i<=l;i++){
//         a[i]=c[i];
//     }
//
// }
//
// void mergesort(int a[],int l,int h){
//     if(l<h){
//         int mid=l+(h-l)/2;
//         mergesort(a,l,mid);
//         mergesort(a,mid+1,h);
//         mergearr(a,l,mid,h);
//     }
// }
// int main() {
//     // Write C code here
//     int n;
//     scanf("%d",&n);
//     int a[n];
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     mergesort(a,0,n-1);
//     for(int i=0;i<n;i++){
//         printf("%d ",a[i]);
//     }
//     return 0;
// }
#include <stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int mid,int h){
    int i, j, k;
    int n1 = mid- l + 1;
    int n2 =  h - mid;
    int a[n1], b[n2];
    for (i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        b[j] = arr[mid+1+j];
    i = 0,j=0,k=l;
    while (i < n1 && j < n2){
        if (a[i] <= b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while (i < n1){
        arr[k++] = a[i++];
    }
    while (j < n2){
        arr[k++] = b[j++];
    }
}
void mergesort(int a[],int l,int h){
    if(l<h){
        int mid=l+(h-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main() {
    // Write C code here
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
