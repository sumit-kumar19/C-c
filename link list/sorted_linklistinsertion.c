#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL;
void display(struct node *p);
void endinsert (struct node *p,int data);
int count(struct node*p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }return c;
}
struct node *givenindex(struct node *p,int index ,int data){
    int c=count(p);
    if(index<0||index>c){
        printf("\n not possible\n");
        return head;

    }
if(index==0){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node *));
    temp->data=data;
    temp->next=p;
    head=temp;
    return head;
}
if(index==count){
     struct node *et;
    et=(struct node *)malloc(sizeof(struct node *));

    et->data=data;
    et->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=et;
    return head;
}
if(index>0&&index<count){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node *));
    temp->data=data;
    temp->next=NULL;
    for(int i=1;i<index-1;i++){
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
    return head;
}
}

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
void display(struct node *p){
    while(p!=NULL){
printf("%d  ",p->data);
p=p->next;
    }
}
void insert (struct node *p,int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node *));
    temp->data=data;
    temp->next=p;
    head=temp;
}
void endinsert(struct node *p,int data){
    struct node *et;
    et=(struct node *)malloc(sizeof(struct node *));

    et->data=data;
    et->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=et;
}
void sortinsert(struct node *p,int data){
     struct node *temp,*q;
    temp=(struct node *)malloc(sizeof(struct node *));
    q=(struct node *)malloc(sizeof(struct node *));
    temp->data=data;
    temp->next=NULL;
    q=NULL;
    if(p==NULL){
        head= temp;
    }
    else if(p==head&&p->data>data){
        temp->next=head;
        head=temp;
    }else{
        while( p!=NULL&&data > p->data){
          //if you write p only it will also work without any error kyuki p jab null hota hai tab p false deta hai while condition mai.
        q=p;
        p=p->next;
    }
    temp->next=q->next;
    q->next=temp;
}
}
void main(){

    int a[]={19,23,45,67,89,90};
    create(a,6);
    display(head);
printf("\n");
insert(head,1);
display(head);
printf("\n");
endinsert(head,800);
display(head);
printf("\n");
  head = givenindex(head,8,150);
  display(head);
  printf("\n");
  sortinsert(head,1000);
  display(head);
free(head);
head = NULL;
}
