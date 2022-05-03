#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node* top=NULL;
struct node* temp=NULL;
void push(int veri){
	struct node *eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;
	eklenecek->next=NULL;
	if(top!=NULL){
		eklenecek->next=top;
}
		top=eklenecek;
		
}
void pop(){
	if(top->data==NULL)
	{
		printf("Yiginin zaten bos");
	}
	else
	{
		temp=top;
		top=temp->next;
		free(temp);	
	}
}
int peek(){
	
	return top->data;
}
void yazdir(){
	temp=top;
	while(temp!=NULL){
		printf("%d=>>",temp->data);
		temp=temp->next;
		
	}printf("NULL");
	
}
int main(){
	
	int secim;
	while(1==1){
		printf("\n1-push islemi :");
		printf("\n2-pop islemi :");
		printf("\n3-peek islemi :");
		printf("\nsecimi yapiniz :");		
		scanf("%d",&secim);
		switch (secim){
			case 1:
				printf("Eklemek istediginiz sayiyi girin :");
				scanf("%d",&secim);
				push(secim);
				yazdir();
				break;	
			case 2:
				pop();
				yazdir();
				break;	
			case 3:
			printf("%d",peek());
				
				break;			
		}
	
	
	}
	
}
