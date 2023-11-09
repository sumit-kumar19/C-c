// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node*next;
// }*head=NULL;
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
// void delefirst(struct node *p){
//     head=head->next;
//     p->next=NULL;
//     free(p);
// }
// void lastdele(struct node *p){
//     // struct node *q;
//     //  q=(struct node*)malloc(sizeof(struct node));
//     // q=NULL;
//     while(p->next->next!=NULL){
//         // q=p;
//         p=p->next;
//
//     }
//     p->next=NULL;
//     free(p->next);
// }
// int count(struct node*p){
//     int c=0;
//     while(p!=NULL){
//         c++;
//         p=p->next;
//     }return c;
// }
// void interdele(struct node *p,int index){
//     struct node *q;
//    q=(struct node*)malloc(sizeof(struct node));
//    q=NULL;
//    for(int i=0;i<index-1;i++){
//        q=p;
//        p=p->next;
//    }
//    q->next=p->next;
//    p->next=NULL;
//    free(p);
// }
// void alldele(struct node *p,int in){
//     int c=count(p)+1;
//     if(head==NULL||in<0||in>c)
//     return ;
//     if(in==1){
//         head=head->next;
//         free(p);
//     }
//     if(in>0&&in<=c){
//         struct node *q;
//    q=(struct node*)malloc(sizeof(struct node));
//    q=NULL;
//    for(int i=0;i<in-1;i++){
//        q=p;
//        p=p->next;
//    }
//    q->next=p->next;
//    p->next=NULL;
//    free(p);
// }
//     }
//
// void display(struct node *p){
//     while(p!=NULL){
// printf("%d  ",p->data);
// p=p->next;
//     }
// }
//
//
// void main(){
//     int a[]={19,23,45,67,89,90};
//     create(a,6);
//     display(head);
//      delefirst(head);
//      printf("\n");
//      display(head);
//      lastdele(head);
//      printf("\n");
//      display(head);
//      interdele(head,4);
//      printf("\n");
//      display(head);
//      alldele(head,1);
//      printf("\n");
//      display(head);
// free(head);
// head = NULL;
//
// }
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL;
void create(int a[],int n);
void display(struct node *p);
void rdisplay(struct node*p);
int search(struct node*p,int key);
int rsearch(struct node*p,int key);
int sum(struct node*p);
void movetohead(struct node*p,int key);
void insertatbeg(struct node*p,int value);
void insertion(struct node*p,int index,int value);
void sorted_insertion(struct node*p,int value);
int deleteatbeg(struct node*p);
int deleteatend(struct node*p);
int intermidiatedelete(struct node*p,int ndex);
int deletion(struct node*p, int index);



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

void main(){
int key,temp;
     int a[]={1,2,4,6,8,9};
    //int a[]={};
    create(a,6);
    int val;
      // sorted_insertion(head,3);
      // sorted_insertion(head,2);
      // sorted_insertion(head,6);
    //  val= deleteatend(head);
      // val = deleteatbeg(head);
    //  val = intermidiatedelete(head ,2);
    val=deletion(head,1);
    display(head);
    printf("\n");
    printf("Deleted value is: %d",val);

}
void display(struct node *p){
    while(p!=NULL){
printf("%d  ",p->data);
p=p->next;
    }
}
int count(struct node*p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }return c;
}
void sorted_insertion(struct node*p,int value){
  struct node*new,*q;
   new = (struct node*)malloc(sizeof(struct node));
new->data=value;
new->next=NULL;
if(p==NULL)
head = new;
else if(p==head && p->data>value){
  new->next=head;
  head=new;
}
  else{
    while(p!=NULL && p->data<value ){
        q=p;
        p=p->next;
      }
          new->next=q->next;
          q->next=new;

      }
}
int deleteatbeg(struct node*p){
  int val;
  head=head->next;
  val=p->data;
  free(p);
  p= NULL;
  return val;
}
//detele at the end with single pointer
int deleteatend(struct node*p){
  int val;
  while(p->next->next!=NULL){
    p=p->next;
  }
  val=p->next->data;
  p->next=NULL;
  free(p->next);
  return val;
}
int intermidiatedelete(struct node*p, int index){
  struct node*q;
  int val,i;
  for(i=0;i<index-1;i++){
    q=p;
    p=p->next;
  }
  q->next=p->next;
  val = p->data;
  p->next=NULL;
  free(p->next);
  val=0;
  return 0;
}


int deletion(struct node*p,int index){
  int val,i;
  struct node*q;
  q=NULL;
  if(head==NULL){
    val=0;
    return val;
  }
  else if(index<1 || index>count(p)){
    val=0;
    return 0;
  }
  else if(p->next==NULL){
    head = head->next;
    val=p->data;
    free(p);
    return val;
  }
  else if(index==1){
    head=head->next;
    val=p->data;
     p= NULL;
    free(p);

    return val;
  }
  else{
    for(i=0;i<index-1;i++){
      q=p;
      p=p->next;
    }
    q->next=p->next;
    val = p->data;
    p->next=NULL;
    free(p);
    return val;
  }

}
