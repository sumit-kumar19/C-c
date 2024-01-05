#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct stack {
    int size;
    int top;
    char* exp;
};

void push(struct stack* st, char data) {
    if (st->top == st->size - 1) {
        printf("stack overflow\n");
    } else {
        st->top++;
        st->exp[st->top] = data;
    }
}

char pop(struct stack* st) {
    char val;
    if (st->top == -1) {
        printf("stack underflow\n");
    } else {
        val = st->exp[st->top];
        st->top--;
    }
    return val;
}

bool isBal(char* exp) {
    struct stack st;
    st.top = -1;
    st.size = strlen(exp);
    st.exp = (char*)malloc(sizeof(char) * st.size);

    for (int i = 0; i < st.size; i++) {
        if (exp[i] == '(')
            push(&st, exp[i]);
        else if (exp[i] == ')') {
            if (st.top == -1)
                return false;
            else
                pop(&st);
        }
    }

    if (st.top == -1)
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