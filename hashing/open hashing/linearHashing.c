#include<stdio.h>
#include<stdlib.h>
#define MAX INT_MAX
#define loo(a,b) for(int i=a;i<(b);i++)
void into(int hasharr[],int n){
  loo(0,n){
  hasharr[i]=-1;
}
}
void insert(int hasharr[],int n,int size){
  if(hasharr[n%size]==-1)
  hasharr[n%size]=n;
  else{
    for(int i=1;i<=size;i++){
      if(hasharr[(n+i)%size]==-1){
        hasharr[(n+i)%size]=n;
        return ;
      }
    }
  }
}
void search(int hasharr[],int value,int size){
  if(hasharr[value%size]==-1)
printf("NOT found\n");
  else{
    for(int i=1;i<=size;i++){
      if(hasharr[(value+i)%size]==value){
        printf("Found\n");
        return  ;
      }
    }
    printf("NOT found\n");
  }
}
int hash(int key,int size){
  return key%size;
}
int main(){

    int n;
    scanf("%d",&n);
    int arr[n];
    int hasharr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
      into(hasharr,n);
    for(int i=0;i<n;i++)
    insert(hasharr,arr[i],n);
    int a;
    scanf("%d",&a);
    search(hasharr,a,n);

    return 0;
}
