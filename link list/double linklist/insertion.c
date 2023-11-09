#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*first=NULL;

void create(int arr[],int n){
  struct node *temp,*last;
  first=(struct node*)malloc(sizeof(struct node*));
  first->data=arr[0];
  first->prev=NULL;
  first->next=NULL;
  last=first;
for(int i=1;i<n;i++){
 temp=(struct node*)malloc(sizeof(struct node));
 temp->data=arr[i];
 temp->next=NULL;
 temp->prev=last;
 last->next=temp;
 last=temp;
}
}

void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int count(struct node*p){
    int c=0;
    while(p!=NULL){
    c++;
    p=p->next;
    }
    return c;
}
void insert0(struct node *p,int data){
    struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node*));
     temp->data=data;
     temp->prev=NULL;
     temp->next=first;
     first->prev=temp;
     first=temp;

}
void inend(struct node *p,int data){
     struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node*));
     temp->data=data;
     temp->prev=NULL;
     temp->next=NULL;
     if(p==NULL){
         first=temp;
     }
     while(p->next!=NULL){
         p=p->next;
     }
     temp->prev=p;
     p->next=temp;
}
void interin(struct node *p,int data,int in){
     struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node*));
     temp->data=data;
     temp->prev=NULL;
     temp->next=NULL;
     if(in<0||count(p)<in)
     return ;
     if(p==NULL){
         first=temp;
     }
     if(in==0){
     temp->next=first;
     first->prev=temp;
     first=temp;
     return;
     }
     else{
     for(int i=1;i<in-1;i++){
         p=p->next;
     }
     if(p->next==NULL){
         temp->prev=p;
         p->next=temp;
     }
     temp->next=p->next;
     p->next->prev=temp;
     p->next=temp;
     temp->prev=p;
}
}
void main(){
    int n,value,index;
    printf("Enter the size:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array:");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    create(arr,n);
    display(first);
    printf("\n");
    int c=count(first);
    printf("Number of elemnt is : %d",c);
    printf("\n");
    insert0(first,5);
    printf("\n");  display(first);
    inend(first,1000);
    printf("\n");  display(first);
    interin(first,56,0);
    printf("\n");  display(first);
    first=NULL;
 free(first);
}
