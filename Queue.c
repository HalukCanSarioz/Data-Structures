#include <stdio.h>
#include <stdbool.h>
#define SIZE 10
typedef struct
{
    int front;
    int rear;
    int value;
    int itemCount;
} element;
element el;
element queue[SIZE];
bool isFull()
{
    return el.itemCount == SIZE;
}
bool isEmpty()
{
    return el.itemCount == 0;
}
void print_queue()
{
    if(!isEmpty())
	{
        printf("Your queue: ");
        for(int i = ++el.front ; i <= el.rear ; i++)
		{
            printf("%d ",queue[i].value);
        }
    } 
	else 
	{
        printf("Queue is empty");
    }
}
void enqueue(int x)
{
    if (!isFull())
    {
        queue[++el.rear].value = x;
        el.itemCount++;
    } 
	else 
	{
        printf("Queue is full!");
    }
}
int dequeue()
{
    if (isEmpty())
    {
        return 0;
    }
	else if (el.front == el.rear)
	{
        el.rear = -1;
        el.front = -1;
        el.itemCount = 0;
    } 
	else 
	{
        el.itemCount--;
        return queue[++el.front].value;
    }
}
void options()
{
    int selection;
    int x;
    int removed_item;
    while (true)
    {
        printf("---------OPTIONS---------\n");
        printf("0 - Print all elements of the queue\n");
        printf("1 - Add an element into the queue\n");
        printf("2 - Remove element from the queue\n");
        printf("3 - Exit\n");
        printf("Select (0-3)? : ");
        scanf("%d", &selection);
        if (selection == 0)
		{
            queueToArray();
            print_queue();
        }
        else if (selection == 1)
		{
            printf("Write the integer to add into the queue: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if (selection == 2)
		{
            removed_item = dequeue();
            printf("Removed item from queue: %d", removed_item);
        }
        else if (selection == 3)
		{
            break;
        }
    }
}
void queueToArray()
{
    int newArray[SIZE-1];
    int l;
    for(int i = ++el.front;i<=el.rear;i++)
	{
        newArray[l] = queue[i].value;
        l++;
    }
    sort(newArray);
}
void sort(int newArray[])
{
    int l = 0;
    int temp;
    for(int i = 0; i <= SIZE; i++)
	{
        for (int j = i + 1; j <= SIZE - 1; j++)
		{
            if (newArray[j] < newArray[i]){
                temp = newArray[i];
                newArray[i] = newArray[j];
                newArray[j] = temp;
            }
        }
    }
    arrayToQueue(newArray);
}
void arrayToQueue(int newArray[])
{
    while (!isEmpty())
	{
        dequeue();
    }
    for(int i = 0; i <= SIZE; i++)
	{
        enqueue(newArray[i]);
    }
}
void main()
{
    el.front = -1;
    el.rear = -1;
    el.itemCount = 0;
    options();
}
