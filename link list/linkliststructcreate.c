#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL;

int search( struct node *p,int key);
int rsearch(struct node *p,int key);
void display(struct node *p);
void rdisplay(struct node *p);
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
int search( struct node *p,int key){
  if(p==NULL)return 0;
  while(p!=NULL){
    if(p->data==key){
    printf("found");
  return 1;}
  p=p->next;
  }
  return 0;
}
int rsearch(struct node *p,int key){
  if(p!=NULL){
    if(key==p->data){
      printf("FOUND");
return 1;
    }
    return rsearch(p->next,key);

  }
  return 0;

}
void main(){

    int a[]={19,23,45,67,89,90};
    create(a,6);
    display(head);
    rdisplay(head);
int c = search(head,23);
if(c==0)
printf("not found");
c = rsearch(head,23);
if(c==0)
printf("not found");





free(head);
head = NULL;

}






void display(struct node *p){
    while(p!=NULL){
printf("%d  ",p->data);
p=p->next;
    }
}
void rdisplay(struct node*p){
    if(p!=NULL){
printf("%d  ",p->data);
return rdisplay(p->next);
    };
}
int count(struct node*p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }return c;
}
