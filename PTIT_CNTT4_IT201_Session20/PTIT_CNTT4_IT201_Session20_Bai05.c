#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int findMax(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftmax=findMax(root->left);
    int rightmax=findMax(root->right);
    int max=root->data;
    if(leftmax>max)
    {
        max=leftmax;
    }
    if(rightmax>max)
    {
        max=rightmax;
    }
    return max;
}
int main()
{
    Node* root=createNode(1);
    Node* node2=createNode(2);
    Node* node3=createNode(3);
    Node* node4=createNode(4);
    Node* node5=createNode(5);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    printf("%d",findMax(root));
    return 0;
}