// Online C compiler to run C program online
#include <stdio.h>

int* mergearr(int a[],int m,int b[],int n){
    int *c;
    c=(int* )malloc((m+n)*sizeof(int));
    int i=0,j=0,k=0;
    while((i<m&&j<n)){
        if(a[i]<b[j])
        c[k++]=a[i++];
        else
        c[k++]=b[j++];
    }
    if(i<m)
    for(;i<m;i++){
        c[k++]=a[i];
    }
    else{
        for(;j<n;j++){
            c[k++]=b[j];
        }
    }
    return c;
}
int main() {
    // Write C code here
    int a[]={1,2,5,7,8,9};
    int b[]={3,4,6,7,10,13,14,16,18,20};
    int m=6;
    int n=10;
    int *c=mergearr(a,m,b,n);
    for(int i=0;i<m+n;i++){
        printf("%d ",c[i]);
    }
    return 0;
}
