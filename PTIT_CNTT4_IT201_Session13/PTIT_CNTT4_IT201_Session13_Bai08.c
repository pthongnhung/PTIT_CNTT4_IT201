#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) exit(1);
    s->arr[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) exit(1);
    return s->arr[(s->top)--];
}

int evaluatePostfix(char* expr) {
    Stack s;
    init(&s);
    int i = 0;
    while (expr[i] != '\0') {
        char c = expr[i];
        if (isdigit(c)) {
            push(&s, c - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            if (c == '+') push(&s, a + b);
            else if (c == '-') push(&s, a - b);
            else if (c == '*') push(&s, a * b);
            else if (c == '/') push(&s, a / b);
        }
        i++;
    }
    return pop(&s);
}

int main() {
    char expr[100];
    printf("Nhap bieu thuc hau to: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    int result = evaluatePostfix(expr);
    printf("Ket qua: %d\n", result);
    return 0;
}
