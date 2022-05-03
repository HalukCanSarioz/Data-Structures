#include <stdio.h>
#include <malloc.h>
struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node* start = NULL;
struct node* dugumOlustur(int veri)
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data = veri;
    yeniDugum->next = NULL;
    yeniDugum->prev = NULL;

    return yeniDugum;
}
void sonaEkle(int veri)
{
    struct node* sonaEklenecek = dugumOlustur(veri);
    if (start == NULL)
    {
        start = sonaEklenecek;
    }
    else
    {
        struct node* temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        sonaEklenecek->prev = temp;
        temp->next = sonaEklenecek;
    }
}
void basaEkle(int veri)
{
    struct node* basaEklenecek = dugumOlustur(veri);
    if (start == NULL)
    {
        start = basaEklenecek;
        return;
    }
    start->prev = basaEklenecek;
    basaEklenecek->next = start;
    start = basaEklenecek;
}
void arayaEkle(int kiminOnune, int eklenecek)
{
    struct node* temp = start;
    struct node* arayaEklenecek = dugumOlustur(eklenecek);
    struct node* onceki = NULL;
    if (start == NULL)
    {
        start = arayaEklenecek;
    }
    else if(start->data == kiminOnune)
    {
        basaEkle(eklenecek);
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == kiminOnune)
            {
                onceki = temp->prev;
                break;
            }
            temp = temp->next;
        }
        temp->prev = arayaEklenecek;
        arayaEklenecek->next = temp;
        arayaEklenecek->prev = onceki;
        onceki->next = arayaEklenecek;
    }
}
void bastanSil()
{
    if (start == NULL)
    {
        printf("\n Liste zaten bos ");
        return;
    }
    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }
    struct node* ikinci = start->next;
    free(start);
    ikinci->prev = NULL;
    start = ikinci;
}
void sondanSil()
{
    if (start == NULL)
    {
        printf("\n Liste zaten bos ");
        return;
    }
    if (start->next == NULL)
    {
        bastanSil();
        return;
    }
    struct node* temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = NULL;
}
void aradanSil(int silinecek)
{
    struct node* temp = start;
    int varmi = 0;

    while (temp->next != NULL)
    {
        if (temp->data == silinecek)
        {
            varmi = 1;
            break;
        }

        temp = temp->next;
    }
    if(varmi == 0)
    {
        printf("\n aradiginiz dugum listede bulunmuyor \n");
        return;
    }
    struct node* sonraki = temp->next;
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = sonraki;
    sonraki->prev = onceki;
}
void yazdir()
{
    struct node* temp = start;

    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int i, secim, sayi, sayi1;
    while (1)
    {
        printf("\n 1- sona eleman ekleme");
        printf("\n 2- basa eleman ekleme");
        printf("\n 3- araya eleman ekleme");
        printf("\n 4- bastan eleman sil");
        printf("\n 5- sondan eleman sil");
        printf("\n 6- aradan eleman sil");
        printf("\n Seciminizi yapin ... ");
        scanf("%d", &secim);
        switch (secim)
        {
            case 1:
                printf("\n Sona Eklemek istediginiz elemani girin  ");
                scanf("%d", &sayi);
                sonaEkle(sayi);
                yazdir();
                break;
            case 2:
                printf("\n Basa Eklemek istediginiz elemani girin  ");
                scanf("%d", &sayi);
                basaEkle(sayi);
                yazdir();
                break;
            case 3:
                printf("\n Araya Eklemek istediginiz sayiyi girin  ");
                scanf("%d", &sayi);
                printf("\n Hangi elemanin onune eklemek istiyorsunuz  ");
                scanf("%d", &sayi1);
                arayaEkle(sayi1, sayi);
                yazdir();
                break;
            case 4:
                bastanSil();
                yazdir();
                break;
            case 5:
                sondanSil();
                yazdir();
                break;
            case 6:
                printf("\n Silinmesini istedigini elemani girin  ");
                scanf("%d", &sayi);
                aradanSil(sayi);
                yazdir();
                break;
        }
    }
    return 0;
}
