#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* link;
};
struct Node *top;
void push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}
void printStack()
{
    if (top == NULL)
        return;
    printf("%d ", top->data);
    top = top->link;
    printStack();
}
void pop()
{
    if (top == NULL)
        return;
    top = top->link;
}
void main()
{
    top = (struct Node *)malloc(sizeof(struct Node));
    top->data = 30;
    top->link = NULL;
    push(19);
    push(354);
    pop();
    pop();
    pop();
    printStack();
}
