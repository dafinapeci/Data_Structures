#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 5
#define NULL_INDEX -1

typedef struct {
    char name[10];
    int link;
} Node;

int main() {
    Node list[SIZE];
    int i;

    printf("Lutfen %d adet dugumun bilgilerini girin:\n", SIZE);

    for (i = 0; i < SIZE; i++) {
        printf("\n%d. dugum icin:\n", i + 1);

        // name alanı için input
        printf("Isim: ");
        scanf("%s", list[i].name);

        // link alanı için input
        printf("Link (son eleman icin -1 girin): ");
        scanf("%d", &list[i].link);
    }


    printf("\nGirilen Dugum Bilgileri:\n");
    printf("Index\tName\tLink\n");
    for (i = 0; i < SIZE; i++) {
        printf("[%d]\t%s\t%d\n", i, list[i].name, list[i].link);
    }

    return 0;
}
