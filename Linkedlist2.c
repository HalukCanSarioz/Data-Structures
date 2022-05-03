#include <stdlib.h>
#include <stdio.h>
struct node
{
	int data;
	struct node *next;	
};
struct node* start=NULL;
struct node* temp=NULL;
void basaEkle(int basa)
{
	struct node*basaeklenecek=(struct node*)malloc(sizeof(struct node));
	basaeklenecek->data=basa;
	basaeklenecek->next=start;
	start=basaeklenecek;
}
void sonaEkle(int sona)
{
	struct node*sonaeklenecek=(struct node*)malloc(sizeof(struct node));
	sonaeklenecek->data=sona;
	sonaeklenecek->next=NULL;
	
	if(start == NULL)
	{
		start=sonaeklenecek;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;	
		}	
		temp->next=sonaeklenecek;
	}
}
void arayaEkle(int soluna,int araya)
{
	struct node*arayaeklenecek=(struct node*)malloc(sizeof(struct node));
	arayaeklenecek->data=araya;
	
	temp=start;
	while(temp->next->data!=soluna)
	{
		temp=temp->next;
	}
	struct node*tutulacak=(struct node*)malloc(sizeof(struct node));
	tutulacak=temp->next;
	temp->next=arayaeklenecek;
	arayaeklenecek->next=tutulacak;
}
void sondanSil()
{
	temp=start;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;	
	}
	free(temp->next);
	temp->next=NULL;
}
void bastanSil()
{
	struct node*tutulacak;
	tutulacak=start->next;
	free(start);
	start=tutulacak;
}
void aradanSil(int x)
{
	struct node* onceki;
	struct node* sonraki;
		temp=start;
		while(temp->next->data!=x)
		{
				temp=temp->next;
		}
		onceki=temp;
		sonraki=temp->next->next;
		free(temp->next);
		onceki->next=sonraki;
}
void yazdir()
{
	temp=start;
	while(temp->next!=NULL)
	{
		printf("%d-->>",temp->data);
		temp=temp->next;
	}printf("%d",temp->data);
}
int main()
{
	int secim,sol,ara,bas,son,sil;
	while(1==1)
	{
		printf("Hangi islemi yapmak istiyorsunuz\n1-basa ekleme \n2-araya ekleme\n3-sona ekleme \n4-Sondan Silme\n5-Bastan sil\n6-Aradan Sil");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
				printf("basa eklenecek sayiyi girin");
				scanf("%d",&bas);
				basaEkle(bas);
				yazdir();
				break;
			case 2:
				printf("araya eklenecek sayiyi girin");
				scanf("%d",&ara);
				printf("hangş sayinin soluna eklenecek ayiyi girin");
				scanf("%d",&sol);
				arayaEkle(sol,ara);
				yazdir();
				break;
			case 3:
				printf("sona eklenecek sayiyi girin");
				scanf("%d",&son);
				sonaEkle(son);
				yazdir();
				break;
			case 4:
				sondanSil();
				yazdir();
				break;
			case 5:
				bastanSil();
				yazdir();
				break;
			case 6:
				printf("Aradan silmek istediginiz sayiyi girin");
				scanf("%d",&sil);
				aradanSil(sil);
				yazdir();
				break;
		}
	}
}

