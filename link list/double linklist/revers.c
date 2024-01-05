// #include <stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node*next;
// }*head=NULL;
// void display(struct node *p);
// void endinsert (struct node *p,int data);
// void create(int a[],int n){
//     struct node *temp,*last;
// head=(struct node*)malloc(sizeof(struct node));
// head->data=a[0];
// head->next=NULL;
// last = head;
// for(int i=1;i<n;i++){
//     temp=(struct node*)malloc(sizeof(struct node));
//     temp->data=a[i];
//     temp->next=NULL;
//     last->next=temp;
//     last=temp;
// }
// }
// void display(struct node *p){
//     while(p!=NULL){
// printf("%d  ",p->data);
// p=p->next;
//     }
// }
// void reverse(struct node *p){
//   struct node *q;
//   q=(struct node*)malloc(sizeof(struct node*));
//   q=NULL;
//   struct node *r;
//   r=(struct node*)malloc(sizeof(struct node*));
//   r=NULL;
//   while(p!=NULL){
//     r=q;
//     q=p;
//     p=p->next;
//     q->next=r;
//   }
//   head=q;
// }
//
// void recursion_reverse(struct node *q,struct node *p){
//   if(p!=NULL){
//   recursion_reverse(p,p->next);
//   p->next=q;}
//   else
//   head=q;
// }
// void main(){
//
//     int a[]={19,23,45,67,89,90};
//     create(a,6);
//     display(head);
//     printf("\n");
//     display(head);
//
// free(head);
// head = NULL;
// }
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
void rever(struct node *p){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node*));
    t=NULL;
    t=p->next;
    p->next=p->prev;
    p->prev=t;

    while(p->prev!=NULL){
            p=p->prev;
        t=p->next;
        p->next=p->prev;
        p->prev=t;


    }
    first=p;
}
void rdup(struct node* p){
  struct node *q,*temp;
q=(struct node*)malloc(sizeof(struct node*));
q=NULL;
while(p->next!=NULL){
      if(p->data==p->next->data){
          q=p->next->next;
          free(p->next);
          p->next=q;
      }
      else{
          p=p->next;
      }
  }

}
int main(){
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
    // rever(first);
    // display(first);
    rdup(first);
    printf("\n");
    display(first);
    first=NULL;
 free(first);
}
