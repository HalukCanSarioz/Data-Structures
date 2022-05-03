#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct treeNode
{
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;
TreeNodePtr insertNode(TreeNodePtr treePtr, int value)
{
    if (treePtr == NULL)
	{
        TreeNodePtr root = (TreeNodePtr)malloc(sizeof(TreeNodePtr));
        root -> leftPtr = NULL;
        root -> rightPtr = NULL;
        root -> data = value;
        return root;
    }
    if (treePtr -> data < value)
	{
        treePtr -> rightPtr = insertNode(treePtr -> rightPtr, value);
        return treePtr;
    }
    treePtr -> leftPtr = insertNode(treePtr -> leftPtr, value);
    return treePtr;
}
void preorder(TreeNodePtr treePtr)
{
    if (treePtr == NULL)
        return;

    printf("%d ", treePtr->data);
    preorder(treePtr->leftPtr);
    preorder(treePtr->rightPtr);
}
void inorder(TreeNodePtr treePtr)
{
    if (treePtr == NULL)
        return;
    inorder(treePtr->leftPtr);
    printf("%d ", treePtr->data);
    inorder(treePtr->rightPtr);
}
void postorder(TreeNodePtr treePtr)
{
    if (treePtr == NULL)
        return;
    postorder(treePtr->leftPtr);
    postorder(treePtr->rightPtr);
    printf("%d ", treePtr->data);
}
int randomNumber()
{
    int num = (rand() % (25)) + 1;
    return num;
}
void main()
{
    TreeNodePtr treePtr = NULL;
    int i;
    srand(time(0));
    for (i = 0 ; i < 10 ; i++)
	{
        treePtr = insertNode(treePtr, randomNumber());
    }
    printf("Preordered Binary Search Tree : ");
    preorder(treePtr);
    printf("\n");
    printf("Inordered Binary Search Tree : ");
    inorder(treePtr);
    printf("\n");
    printf("Postordered Binary Search Tree : ");
    postorder(treePtr);
    printf("\n");
}
