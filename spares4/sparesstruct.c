#include<stdio.h>
#include<stdlib.h>
struct element{
  int r;
  int c;
  int va;
}e;
struct sparse{
  int m;
  int n;
  int nnz;
  struct element *e;
} s,s1;
void display(struct sparse s);
void add(struct sparse s1,struct sparse s2);
void create( struct sparse *s){
  printf("Enter no of row");
  scanf("%d",&s->m);
    printf("Enter no of colum");
    scanf("%d",&s->n );
      printf("Enter no of non zero elements");
scanf("%d",&s->nnz);
 s->e=(struct element *)malloc(s->nnz*sizeof(struct element));
 printf("enter non zero elements");
 for(int i=0;i<s->nnz;i++){
   scanf("%d%d%d",&s->e[i].r,&s->e[i].c,&s->e[i].va);
 }

}
void add(struct sparse s,struct sparse s1){
int i=0,j=0,k=0;
  while(i<s.nnz||j<s1.nnz){
   if(s.e[i].r < s1.e[j].r)
    printf("%d ",s.e[i++].va);
    else if(s.e[i].r > s1.e[j].r)
    printf("%d ",s1.e[j++].va);
    else if(s.e[i].r == s1.e[j].r){
      if(s.e[i].c < s1.e[j].c)
      printf("%d ",s.e[i++].va);
      else if(s.e[i].c > s1.e[j].c)
      printf("%d ",s1.e[j++].va);
      else if(s.e[i].c == s1.e[j].c)
      printf("%d ",s.e[i++].va+s1.e[j++].va);
    }
    else{
    printf("0 ");
}

    printf("\n");
  }
}
void display(struct sparse s){
  int i,j,k=0;
  for(i=0;i<s.m;i++){
    for(j=0;j<s.n;j++){
      if(i==s.e[k].r&&j==s.e[k].c)
      printf("%d ",s.e[k++].va);
      else
      printf("0 ");
    }
    printf("\n");
  }
}
void main(){
  create(&s);
  display(s);
  create(&s1);
  display(s1);
  add(s,s1);
  free(s1.e);
  free(s.e);
}
