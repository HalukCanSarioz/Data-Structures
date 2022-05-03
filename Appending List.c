#include <stdlib.h>
#include <stdio.h>
struct node
{
		int data;
		struct node *next;
};
struct node* start = NULL;
struct node* temp = NULL;
void sonaEkle(int veri)
{
		struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
		eklenecek -> data = veri;
		eklenecek -> next = NULL;
		if(start == NULL)
		{
			start = eklenecek;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{	
				temp = temp->next;
			}
			temp->next=eklenecek;
		}
}
void yazdir()
{
	temp = start;
	while(temp->next!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp -> next;
	}
	printf("%d ",temp->data);
}
int main()
{
	int secim;
	while(1)
	{
		printf("\n");
		printf("bir tane sayi giriniz ");
		scanf("%d",&secim);
		sonaEkle(secim);
		yazdir();
	}	
}
