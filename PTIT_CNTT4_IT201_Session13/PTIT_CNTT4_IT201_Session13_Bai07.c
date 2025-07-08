#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *arr;
    int top;
    int cap;
} Stack;

// Tạo stack
Stack* createStack(int cap) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->arr = (char*)malloc(sizeof(char) * cap);
    return stack;
}


int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char c) {
    stack->arr[++stack->top] = c;
}


char pop(Stack *stack) {
    if (!isEmpty(stack))
        return stack->arr[stack->top--];
    return '\0';
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isValidParentheses(char *expr) {
    Stack *stack = createStack(strlen(expr));

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(stack) || !isMatching(pop(stack), c)) {
                free(stack->arr);
                free(stack);
                return 0;
            }
        }
    }

    int valid = isEmpty(stack);
    free(stack->arr);
    free(stack);
    return valid;
}

int main() {
    char expr[1000];
    printf("Nhap bieu thuc: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Xóa ký tự newline

    if (isValidParentheses(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
