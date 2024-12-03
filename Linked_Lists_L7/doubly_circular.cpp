//this one is not using active prev node so not usefull but it is doubly and circular
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    int katsayı;
    int exponen;
    struct node* next;
    struct node* prev;
};

int sayaç = 0;

void insert_item(struct node** head, int katsayı, int exponen) {
    struct node* temp = (struct node*)malloc(sizeof(struct node)); // Yeni düğüm için bellek ayır

    temp->exponen = exponen; // Yeni elemanı ekler
    temp->katsayı = katsayı;

    if (*head == NULL) {  // Eğer liste boşsa
        *head = temp;  // Başlangıç elemanını head olarak ayarla
        temp->next = *head;  // Circular bağlantıyı oluştur
        temp->prev = *head;  // Prev işaretçisi de başa gitsin
    }
    else {
        struct node* current = *head;
        while (current->next != *head) {  // Liste sonuna git
            current = current->next;
        }
        current->next = temp;  // Son düğümün next'ini yeni düğüme bağla
        temp->prev = current;  // Yeni düğümün prev işaretçisini eski son düğüme bağla
        temp->next = *head;  // Yeni düğümün next'ini başa bağla
        (*head)->prev = temp;  // Baş düğümün prev işaretçisini yeni düğüme bağla
    }
    sayaç++;
}
int compare(int exponen, int exponen2) {
    if (exponen > exponen2)
    {
        return 1;
    }
    if (exponen == exponen2)
    {
        return 0;
    }
    if (exponen < exponen2)
    {
        return -1;
    }
}

void addition(struct node** head, struct node** head2, struct node** head3) {
    struct node* head1 = *head;
    struct node* head4 = *head2;
    do {
        switch (compare(head1->exponen, head4->exponen)) {
        case 1:  // head1'in üssü büyük
            insert_item(head3, head1->katsayı, head1->exponen);
            head1 = head1->next;
            break;

        case -1: // head2'nin üssü büyük
            insert_item(head3, head4->katsayı, head4->exponen);
            head4 = head4->next;
            break;

        case 0:  // Üsler eşit
            insert_item(head3, head1->katsayı + head4->katsayı, head1->exponen);
            head1 = head1->next;
            head4 = head4->next;
            break;
        }
    } while (head1 != *head && head4 != *head2);
    

    // head1 veya head4'ün bitmemiş kısmını ekleyelim
    while (head1 != *head) {
        insert_item(head3, head1->katsayı, head1->exponen);
        head1 = head1->next;
    }

    while (head4 != *head2) {
        insert_item(head3, head4->katsayı, head4->exponen);
        head4 = head4->next;
    }
}

void free_list(struct node** head) {
    struct node* temp;
    if (*head == NULL) return;  // Eğer liste boşsa, hiçbir şey yapma

    temp = *head;
    do {
        struct node* next = temp->next;
        free(temp);  // Geçici düğümü serbest bırak
        temp = next;
    } while (temp != *head);  // Başka bir düğüme gidene kadar devam et

    *head = NULL;  // Listeyi null yap
}

void print(struct node** head) {
    if (*head == NULL) {
        printf("Liste boş\n");
        return;
    }

    struct node* current = *head;
    printf("\ndüz list: ");

    do {
        printf("%d-%d\t", current->katsayı, current->exponen);
        current = current->next;
    } while (current != *head);  // Başta olduğumuzda dur
}

int main() {
    struct node* head = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;

    insert_item(&head, 6, 3);
    insert_item(&head, 15, 4);
    insert_item(&head, 30, 5);
    insert_item(&head, 40, 6);
    printf("\nlist 1\n");
    print(&head);

    insert_item(&head2, 7, 3);
    insert_item(&head2, 16, 4);
    insert_item(&head2, 31, 1);
    insert_item(&head2, 42, 0);
    printf("\nlist 2\n");
    print(&head2);

    addition(&head, &head2, &head3);
    printf("\ntoplanmış liste\n");
    print(&head3);

    free_list(&head);
    free_list(&head2);
    free_list(&head3);

    return 0;
}
