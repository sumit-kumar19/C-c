#include<stdio.h>
#include<stdlib.h>
#define size 10
#define into(a) int a;scanf("%d",&a);

struct node{
    int data;
    struct node *next;
};

struct node *chain[size];
void init(){
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value % size;
    if(chain[key] == NULL)
        chain[key] = newNode;
    else{
        struct node *temp = chain[key];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(int value){
    int key = value % size;
    struct node *temp = chain[key];
    while(temp){
        if(temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void display(){
     printf("Array\t\t\tlinklist\n");
    for(int i = 0; i < size; i++){
        struct node *temp = chain[i];

        printf("listhead '%d'\t",i);
        while(temp){
            printf("%d--",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    init();
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    insert(arr[i]);
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);
    display();
    into(s);
    if(search(s))
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
    return 0;
}
