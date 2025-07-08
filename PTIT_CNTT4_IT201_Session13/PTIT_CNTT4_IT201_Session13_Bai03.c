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
    Stack *myStack = (Stack *)malloc(sizeof(Stack));
    myStack->top=-1;
    myStack->cap=cap;
    myStack->arr=(int *)malloc(sizeof(int)*cap);
    return myStack;
}
int isFull(Stack *myStack)
{
    if (myStack->top==myStack->cap-1)
    {
        return 1;
    }
    return 0;
}
int pushStack(Stack* stack,int value)
{
    if(isFull(stack))
    {
        printf("Stack is full\n");
        return 0;
    }
    stack->top=stack->top+1;
    stack->arr[stack->top] = value;
    return 1;
}
int isEmpty(Stack *myStack)
{
    if(myStack->top==-1)
    {
        return 1;
    }
    return 0;
}
int Pop(Stack *myStack)
{
    if(isEmpty(myStack))
    {
        printf("No elements in stack\n");
        return 0;
    }
    myStack->top=myStack->top-1;
    return myStack->arr[myStack->top+1];
}
int main()
{
    Stack *myStack=createStack(5);
    pushStack(myStack,10);
    pushStack(myStack,20);
    pushStack(myStack,30);
    pushStack(myStack,40);
    pushStack(myStack,50);
    printf("%d\n",Pop(myStack));
    printf("%d\n",Pop(myStack));
    printf("%d\n",Pop(myStack));
    printf("%d\n",Pop(myStack));
    printf("%d\n",Pop(myStack));
    printf("%d\n",Pop(myStack));

    free(myStack->arr);
    free(myStack);
    return 0;
}
