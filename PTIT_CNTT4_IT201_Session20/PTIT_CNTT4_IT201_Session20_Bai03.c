#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* right;
    struct Node* left;
}Node;
typedef struct Queue
{
    Node** arr;
    int front;
    int rear;
    int cap;
}Queue;
Node* createNode(int value)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}
Queue* createQueue(int cap)
{
    Queue* newQueue=(Queue*)malloc(sizeof(Queue));
    newQueue->cap=cap;
    newQueue->front=0;
    newQueue->rear=-1;
    newQueue->arr=(Node**)malloc(newQueue->cap*sizeof(Node*));
    return newQueue;
}
int isFull(Queue* queue)
{
    if(queue->rear==queue->cap-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Queue* queue)
{
    if(queue->rear<queue->front)
    {
        return 1;
    }
    return 0;
}
void enQueue(Queue* queue, Node* node)
{
    if(isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear]=node;
}
Node* deQueue(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
Node* insertNode(Node* root, int data)
{
    //B1: Khoi tao node moi
    Node* newNode=createNode(data);
    //Kiem tra cay rong
    if (root == NULL)
    {
        return root=newNode;
    }
    //B2: Khoi tao hang doi va dua node goc vao hang doi
    Queue* newQueue=createQueue(100);
    enQueue(newQueue, root);
    //B3: Duyet den khi nao hang doi trong
    while(!isEmpty(newQueue))
    {
        //B4: Lay node dau tien cua hang doi ra
        Node* node=deQueue(newQueue);
        //B5: Kiem tra node con ben trai cua node dc lay ra
        if (node->left!=NULL)
        {
            //B5.1: Neu co thi day node con ben trai vao hang doi
            enQueue(newQueue, node->left);
        }else
        {
            //B5.2: Neu khong co thi chen node moi vao vi tri ben trai
            node->left=newNode;
            free(newQueue->arr);
            free(newQueue);
            return root;
        }
        //B6: kiem tra node con ben phai cua node dc lay ra
        if (node->right!=NULL)
        {
            //B6.1:Neu co thi day node con ben phai vao hang doi
            enQueue(newQueue, node->right);
        }else
        {
            //B6.2: Neu khong co thi them node moi vao vi tri ben phai
            node->right=newNode;
            free(newQueue->arr);
            free(newQueue);
            return root;
        }
    }
    return root;
}
int main()
{
    Node* root=createNode(1);
    Node* node1=createNode(2);
    Node* node2=createNode(3);
    Node* node3=createNode(4);
    Node* node4=createNode(5);
    Node* node5=createNode(6);
    root->left=node1;
    root->right=node2;
    node1->left=node3;
    node1->right=node4;
    node2->left=node5;
    preorder(root);
    printf("\n");
    insertNode(root,7);
    preorder(root);

}