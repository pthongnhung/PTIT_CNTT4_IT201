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
    stack->arr=(int*)malloc(sizeof(Stack)*cap);
    return stack;
}
int isFull(Stack *myStack)
{
    if (myStack->top==myStack->cap-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Stack *myStack)
{
    if(myStack->top==-1)
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
    printf("%d\n",myStack->top);
    printf("%d\n",myStack->cap);
    pushStack(myStack,10);
    pushStack(myStack,20);
    pushStack(myStack,30);
    pushStack(myStack,40);
    pushStack(myStack,50);
    for (int i=myStack->top;i>=0;i--)
    {
        printf("%d\n",myStack->arr[i]);
    }
    printf("hihi: %d",Pop(myStack));


    return 0;
}