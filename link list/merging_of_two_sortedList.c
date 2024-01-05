#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL,*head2=NULL,*third = NULL, *last = NULL;
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
void  merge(struct node *first,struct node *second){
    if(first->data<second->data){
        third=last=first;
        first=first->next;
        last->next=NULL;
    }
    else{
        third=last=second;
        second=second->next;
        last->next=NULL;
    }
    while((first!=NULL&&second!=NULL)){
        if(first->data<second->data){
             last->next = first;
             last = first;
               first = first->next;
            last->next = NULL;
        }
        else{
             last->next = second;
             last = second;
             second = second->next;
             last->next = NULL;
        }
    }
    if(first!=NULL)
    last->next=first;
    else
    last->next=second;
}
void main(){

    int a[]={10,20,30,40};
    create(a,4);
    display(head);
    int b[]={5,15,25,35,45,50};
    createsec(b,6);
     printf("\n");
    display(head2);

    merge(head,head2);
    printf("\n");
    display(third);

free(head);
head = NULL;
}
