#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct elementi{
	int num;
	struct elementi *next;
}*stelement;
int zauzimanjeMemorije(int);
void formiranjeNiza(int*, int);
void formiranjePP(int* , int);
void prikaziListu();
void pretrazivanjeNiza(int*, int);
void pretrazivanjePopisa(int);


int main(void) {
    int n;
    
    int* array = NULL;
    printf(" Unesite broj elemenata : ");
    scanf("%d", &n);
    array = zauzimanjeMemorije(n);
    if (array == NULL) {
        return NULL;
    }
    
    formiranjeNiza(array, n);
    formiranjePP(array, n);
    printf("\n Podatci u listi : \n");
    prikaziListu();
    pretrazivanjeNiza(array, n);
    pretrazivanjePopisa(n);
    return 0;
}

int zauzimanjeMemorije(int n)
{
    int* array = NULL;
    array = (int*)calloc(n, sizeof(int));

    if (array == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        *(array + i) = (int)calloc(n, sizeof(int));

        if (*(array + i) == NULL)
        {
            return NULL;
        }
    }

    return array;
}

void formiranjeNiza(int* array, int n){
    time_t t1, t2;
    srand((unsigned)time(NULL));
    t1 = clock();
    for (int i = 0; i < n; i++) {
        
        array[i]=rand();
        printf("%d\n", array[i]);
    }
    t2 = clock();
    
    printf("Vrijeme trajanja formiranja niza je % dms\n", t2 - t1);
}


void formiranjePP(int* array, int n)
{
    time_t t1, t2;
    struct elementi* fnNode, * tmp;
    int num, i = 0;
    stelement = (struct elementi*)malloc(sizeof(struct elementi));

    if (stelement == NULL) 
    {
        printf(" Memorija ne moze biti alocirana.");
    }
    else
    {
        int num = (*(array + i));
        stelement->num = num;
        stelement->next = NULL;
        tmp = stelement;
        t1 = clock();
        for (i = 1; i <= n-1; i++)
        {
            fnNode = (struct elementi*)malloc(sizeof(struct elementi));
            if (fnNode == NULL)
            {
                printf(" Memorija ne moze biti alocirana.");
                break;
            }
            else
            {
                num = (*(array + i));

                fnNode->num = num;  
                fnNode->next = NULL; 

                tmp->next = fnNode; 
                tmp = tmp->next;
            }
        }
        t2 = clock();
        printf("Vrijeme trajanja formiranja PP je % dms\n", t2 - t1);
    }
}
void prikaziListu()
{
    struct elementi* tmp;
    if (stelement == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stelement;
        while (tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);       
            tmp = tmp->next;                    
        }
    }
}

void pretrazivanjeNiza(int* array, int n) {
    time_t t1, t2;
    int key;
    int flag = 0;
    printf("\nUnesite broj: ");
    scanf("%d", &key);
    t1 = clock();
    for (int i = 0; i < n; i++)
    {
        if (key == array[i])
            flag = 1;
        break;
    }
    if (flag == 1)
        printf("\nBroj %d postoji u nizu\n", key);
    else
        printf("\nBroj %d ne postoji u nizu\n", key);
    t2 = clock();
    printf("Vrijeme trajanja pretrazivanja niza je % dms\n", t2 - t1);

}

void pretrazivanjePopisa(int n) {
    time_t t1, t2;
    struct elementi* tmp;
    int key;
    int flag = 0;
    printf("\nUnesite broj: ");
    scanf("%d", &key);


    tmp = stelement;
    t1 = clock();
    while (tmp != NULL)
    {
        if (tmp->num == key) {
            flag = 1;
            break;
        }
        else {
            flag = 0;
        }
        tmp = tmp->next;
    }
    t2 = clock();
    
    if (flag == 1)
        printf("\nBroj %d postoji u nizu\n", key);
    else
        printf("\nBroj %d ne postoji u nizu\n", key);
    printf("Vrijeme trajanja pretrazivanja PP je % dms\n", t2 - t1);
    
}
