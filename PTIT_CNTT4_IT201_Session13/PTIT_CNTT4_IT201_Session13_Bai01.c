#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
    int *arr;
    int top;
    int cap;
}Stack;
Stack *createStack(int cap)
{
    Stack *stack=(Stack*)malloc(sizeof(Stack));
    stack->cap=cap;
    stack->top=-1;
    stack->arr=(Stack*)malloc(sizeof(Stack)*cap);
    return stack;
}
int main()
{
    Stack *myStack=createStack(5);
    printf("%d\n",myStack->top);
    printf("%d\n",myStack->cap);
    return 0;
}