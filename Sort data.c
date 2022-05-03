#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#define SIZE 1024
struct Node
{
    char *course;
    long code;
    struct Node* next;
};
void insert(struct Node *root, char *str, long l)
{
    while(root->next != NULL)
	{
        root = root->next;
    }
    root->next = (struct Node *)malloc(sizeof(struct Node));
    root->next->course = str;
    root->next->code = l;
    root->next->next = NULL;
}
void printList(struct Node* n)
{
    while(n != NULL)
	{
        printf("%ld: %s\n", n->code, n->course);
        n = n->next;
    }
}
int main()
{
    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    root->course = "First";
    root->code = 0;
    root->next = NULL;
    FILE *file;
    char line[SIZE];
    char *new;
    char *new2;
    char *p;
    long i;
    file = fopen("Data.dat", "r");
    if (file == NULL)
        exit(EXIT_FAILURE);
    fread(&line, sizeof(char), SIZE, file);
    new = strtok(line, "\n");
    new2 = new;
    while(new != NULL)
	{
        while(*new2)
		{
            if(isdigit(*new2))
			{
                i = strtol(new2, &new2, 10);
            }
            else
			{
                new2++;
            }
        }
        root = insert(root, new, i);
        new = strtok(NULL, "\n");
        new2 = new;
	}
    printList(root);
    fclose(file);
    exit(EXIT_SUCCESS);
}
