#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void printList(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printList(root->next);
}
void reversePrintList(struct Node *root)
{
    if (root == NULL)
        return;

    reversePrintList(root->next);
    printf("%d ", root->data);
}
void insert(struct Node *root, int x)
{
    while(root->next != NULL)
	{
        root = root->next;
    }
    root->next = (struct Node *)malloc(sizeof(struct Node));
    root->next->data = x;
    root->next->next = NULL;
}
void delete(struct Node *root, int n)
{
    struct Node *temp1 = root;
    if (n == 1)
	{
        root = temp1->next;
        free(temp1);
    }
	else 
	{
        for(int i=0 ; i <n-2 ; i++)
		{
            if(temp1->next != NULL)
			{
                temp1 = temp1->next;
            }
        }
        struct Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}
struct Node * reverse(struct Node *root)
{
    struct Node *cur, *prev, *next;
    cur = root;
    prev = NULL;
    while(cur != NULL)
	{
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    root = prev;
    return root;
}
int main()
{
    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 20;
    root->next = NULL;
    insert(root, 30);
    insert(root, 1);
    insert(root, 5);
    insert(root, 6);
    insert(root, 19);
    insert(root, 17);
    insert(root, 21);
    insert(root, 56);
    insert(root, 98);
    insert(root, 41);
    printf("List: ");
    printList(root);
    printf("\n");
    printf("Reversed List : ");
    reversePrintList(root);
    printf("\n");
}
