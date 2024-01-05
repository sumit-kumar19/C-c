#include <stdio.h>
#include <stdlib.h>
struct stack
{int size;
int top;
int * arr;
};
void create (struct stack *st){
printf("Enter the size of stack");
scanf("%d",&st->size);
st->top=-1;
st->arr=(int *)malloc(sizeof(int)*st->size);
}
void display(struct stack *st){
  for(int i=st->top;i>=0;i--){
    printf("%d\n",st->arr[i]);
  }
}
void push( struct stack * st,int data){
  if(st->top==st->size-1){
    printf("stack overflow");
  }
  else{
    st->top++;
    st->arr[st->top]=data;
  }
}
int pop(struct stack *st){
  int val;
  if(st->top==-1){
    printf("stack underflow");
  }
  else{
    val=st->arr[st->top];
  }
  return val;
}
void peek(struct stack *st){
  if(st->top==-1){
    printf("stack underflow");
  }
  else{
    printf("%d\n",st->arr[st->top]);
  }
}
int size(struct stack *st){
return st->top+1;
}
int main(){
    struct stack st;
    create(&st);
  push(&st,10);
  push(&st,20);
  push(&st,30);
  display(&st);
  printf("%d",pop(&st));
  pop(&st);
  printf("%d",size(&st));
  push(&st,40);
  push(&st,50);
  push(&st,60);
  display(&st);
  pop(&st);
  pop(&st);
  printf("%d",pop(&st));
  display(&st);
  return 0;
}
