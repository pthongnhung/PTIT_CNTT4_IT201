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
int findLevel(Node* root, int value) {
    int helper(Node* node, int value, int level) {
        if (node == NULL) return -1;
        if (node->data == value) return level;

        int left = helper(node->left, value, level + 1);
        if (left != -1) return left;

        return helper(node->right, value, level + 1);
    }

    return helper(root, value, 0); // bắt đầu từ level 0
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
    int value;
    printf("Nhap gia tri can tim tang: ");
    scanf("%d",&value);
    int level = findLevel(root, value);
    if (level != -1)
    {
        printf("%d",level);
    }else
    {
        printf("khong tim thay");
    }
    return 0;
}