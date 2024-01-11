#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct que
{int f,l;
int size;
int cap;
int * arr;
};
void create ( struct que *q,int cap){
    q->f=q->l=-1;
    q->cap=cap;
    q->size=0;
    q->arr=(int *)malloc(cap*sizeof(int));

}
bool isfull(struct que *q){
    if(q->l==q->cap-1)
    return true;
    return false;
}
bool isempty(struct que *q){
    if(q->f==q->l)
    return true;
    return false;
}
void enque(struct que *q,int data){
    if(!isfull(q)){
        q->l++;
        q->arr[q->l]=data;
        q->size++;
    }
    else
    printf("Overflow\n");
}

int deque(struct que *q){
    int x=-1;
    if(isempty(q)){
        return x;
    }else
    x=q->arr[q->f+1];
    q->f++;
    q->size--;
    return x;
}
void display(struct que *q){
    for(int i=q->f+1;i<=q->l;i++)
    printf("%d \t",q->arr[i]);
    printf("\n");
}
void main(){
    int cap;
    struct que q;
    scanf("%d",&cap);
    create(&q,cap);
    enque(&q,20);
    enque(&q,10);
    enque(&q,30);
    int y=deque(&q);
    printf("%d\n",y);
    display(&q);
}
