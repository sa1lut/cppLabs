#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)
#define PR_double(x) printf("x=%u, *x=%e, &x=%u\n", x, *x, &x)
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 

    printf("Указатели на целые числа:\n");
    int mas[] = {100, 200, 300};
    int *ptr1, *ptr2;

    ptr1 = mas; 
    ptr2 = &mas[2]; 

    PR(ptr1); 
    ptr1++; 
    PR(ptr1); 
    PR(ptr2); 
    ++ptr2; 
    printf("ptr2 - ptr1=%u\n", ptr2 - ptr1); 


    printf("\nУказатели на вещественные числа:\n");
    double dmas[] = {1.5, 2.5, 3.5};
    double *dptr1, *dptr2;
    dptr1 = dmas;
    dptr2 = &dmas[2];
    PR_double(dptr1);
    dptr1++;
    PR_double(dptr1);
    PR_double(dptr2);
    ++dptr2;
    printf("dptr2 - dptr1 = %u\n", dptr2 - dptr1);


    printf("\nУказатели на буллевые значения:\n");
    bool bmas[] = {true, false};
    bool *bptr1, *bptr2;
    bptr1 = bmas;
    bptr2 = &bmas[1];
    PR(bptr1);
    PR(bptr2);
    printf("bptr2 - bptr1 = %u\n", bptr2 - bptr1);

    return 0;
}