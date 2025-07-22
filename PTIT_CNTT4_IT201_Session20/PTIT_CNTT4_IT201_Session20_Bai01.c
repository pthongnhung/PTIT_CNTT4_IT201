#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void printNode(Node* node) {
    if (node == NULL) {
        printf("Node rong!\n");
        return;
    }
    printf("node = {\n");
    printf("   data: %d,\n", node->data);
    printf("   left->%s,\n", node->left == NULL ? "NULL" : "Node");
    printf("   right->%s\n", node->right == NULL ? "NULL" : "Node");
    printf("}\n");
}
int main()
{
    Node* root=createNode();
    printNode(root);
    return 0;
}