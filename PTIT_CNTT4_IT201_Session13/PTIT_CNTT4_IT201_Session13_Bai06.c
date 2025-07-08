#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct Stack
{
    char *arr;
    int top;
    int cap;
}Stack;
Stack *createStack(int cap)
{
    Stack *myStack = (Stack *)malloc(sizeof(Stack));
    myStack->cap = cap;
    myStack->top = -1;
    myStack->arr= (char *)malloc(sizeof(char) * cap);
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
int Push(Stack *myStack, char value)
{
    if (isFull(myStack))
    {
        printf("overflow");
        return 0;
    }
    myStack->top=myStack->top+1;
    myStack->arr[myStack->top]=value;
    return 1;
}
int isEmpty(Stack *myStack)
{
    if (myStack->top==-1)
    {
        return 1;
    }
    return 0;
}
char Pop(Stack *myStack)
{
    if (isEmpty(myStack))
    {
        printf("underflow");
        return 0;
    }
    myStack->top=myStack->top-1;
    return myStack->arr[myStack->top+1];
}
int isSymmetric(char str[])
{
    int len=strlen(str);
    Stack *myStack =createStack(len);
    for(int i=0;i<len;i++)
    {
        Push(myStack,str[i]);
    }
    for(int i=0;i<len;i++)
    {
        char popped=Pop(myStack);
        if (str[i]!=popped)
        {
            free(myStack->arr);
            free(myStack);
            return 0;
        }
        free(myStack->arr);
        free(myStack);
        return 1;
    }
}
int main()
{
    char str[1000];
    printf("Vui long nhap chuoi: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    if (isSymmetric(str))
    {
        printf("TRUE");
    }else
    {
        printf("FALSE");
    }
    return 0;
}
