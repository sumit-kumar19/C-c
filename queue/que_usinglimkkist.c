#include <stdio.h>
#include<stdlib.h>
struct qlist {
    int data;
    struct qlist* next;
}*fro=NULL,*r=NULL;
void enque(int data){
    struct qlist * temp;
    temp=(struct qlist *)malloc(sizeof(struct qlist));
    if(temp==NULL){
    printf("heap overflow");
    return ;
    }
    temp->next=NULL;
    temp->data=data;
    if(fro==NULL&&r==NULL)
    fro=r=temp;
    else{
        r->next=temp;
        r=temp;
    }
}
int deque(void){
    struct qlist *p;
    p=fro;
    int x=p->data;
    fro=fro->next;
    free(p);
    return x;
}
void display(void){
    struct qlist *p=fro;
    while(p!=NULL){
    printf("%d\t",p->data);
    p=p->next;
}
    return ;
}
   void main(){
    enque(20);
    enque(10);
    enque(30);
    int y=deque();
    printf("%d\n",y);
    display();
}
