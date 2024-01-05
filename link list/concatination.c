#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL,*head2=NULL;
void display(struct node *p);
void create(int a[],int n){
    struct node *temp,*last;
head=(struct node*)malloc(sizeof(struct node));
head->data=a[0];
head->next=NULL;
last = head;
for(int i=1;i<n;i++){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a[i];
    temp->next=NULL;
    last->next=temp;
    last=temp;
}
}
void createsec(int a[],int n){
    struct node *temp,*last;
head2=(struct node*)malloc(sizeof(struct node));
head2->data=a[0];
head2->next=NULL;
last = head2;
for(int i=1;i<n;i++){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a[i];
    temp->next=NULL;
    last->next=temp;
    last=temp;
}
}
void display(struct node *p){
    while(p!=NULL){
printf("%d  ",p->data);
p=p->next;
    }
}
void concati(struct node *p,struct node *q){
    while(p->next!=NULL){
        p=p->next;

    }
    p->next=q;
    head2=NULL;
}
void main(){

    int a[]={19,23,45,67,89,90};
    create(a,6);
    display(head);
    int b[]={19,20,30,40,50,60};
    createsec(b,6);
     printf("\n");
    display(head2);
    concati(head,head2);
    printf("\n");
    display(head);

free(head);
head = NULL;
}
