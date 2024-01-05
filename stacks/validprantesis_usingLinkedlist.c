#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct stack {
    char ch;
    struct stack *next;
}*head=NULL;

void push(struct stack*head ){
    struct stack *newNode = malloc(sizeof(struct stack));
    newNode->ch = '(';
    newNode->next = head;
    head = newNode;
}

void pop(struct stack *p){
    struct stack *temp;
    if(head == NULL)
        printf("Stack is Empty\n");
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
}

bool isBal(char* exp) {
    // struct stack st;
    // st.top = -1;
    // st.size = strlen(exp);
    // st.exp = (char*)malloc(sizeof(char) * st.size);
for(int i=0;exp[i]!='\0';i++){
    if (exp[i] == '(')
            push(head);
        else if (exp[i] == ')') {
            if (head==NULL)
                return false;
            else
                pop(head);
        }
    
}
    if (head==NULL)
        return true;
    else
        return false;
}

int main() {
    char exp[] = "((a+b)*(b+c))";
    if (isBal(exp))
        printf("Expression is balanced\n");
    else
        printf("Expression is not balanced\n");

    return 0;
}