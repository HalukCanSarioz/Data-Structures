#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *root=NULL;
struct node *temp=NULL;
void enqueue(int veri)
{
	struct node* eklenecek=(struct node *)malloc(sizeof(struct node));
	eklenecek->data=veri;
	eklenecek->next=NULL;
	if(root!=NULL)
	{
		eklenecek->next=root;
	}
	root=eklenecek;
}
void denqueue()
{
	if(root!=NULL)
	{
	temp=root;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;	
	}	
	else 
	{
		printf("Liste Bosss");
	}
}
void yazdir()
{
	temp=root;
	while(temp!=NULL)
	{
		printf("%d=>",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int secim;
	while(1==1)
	{
		printf("Hangi Islemi Yapmak Istiyorsun \n1-Enqueue\n2-Denqueue");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
				printf("kuyruga eklemek istedğiniz sayiyi girin");
				scanf("%d",&secim);
				enqueue(secim);
				yazdir();
				break;
			case 2:
				denqueue();
				yazdir();
				break;			
		}
	}	
}
