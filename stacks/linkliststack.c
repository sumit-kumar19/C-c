struct node {
    int data;
    struct node *next;
}*top=NULL;

void push(struct node *top,int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node ));
    if(t==NULL)
    printf("heap overflow");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
void pop(struct node *head){
    struct node *temp;
    if(head == NULL)
        printf("Stack is Empty\n");
    else{
        printf("Poped element = %d\n", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    push(top,10);
    push(top,20);
    push(top,30);
    display(top);
    printf("\n");
    pop(top);
    display(top);
    printf("\n");
    pop(top);
    display(top);
    return 0;
}