#include <stdio.h>

#include "sort.h"

void print_vet(int* vet, int len){
    for(int i = 0; i < len; i++){
        printf("%d; ", vet[i]);
    }
    printf("\n");
}

void test_mergesort(){
    int vet[] = {1,5,2,4,1,0,3,0,0,5};
    int len = sizeof(vet) / sizeof(vet[0]);

    printf("--> [Merge sort]\n\n");
    print_vet(vet, len);
    mergesort(vet, 0, len - 1);
    print_vet(vet, len);
    printf("*********************************************\n");
}

void test_quicksort_v01(){
    int vet[] = {1,5,2,4,1,0,3,0,0,5};
    int len = sizeof(vet) / sizeof(vet[0]);

    printf("--> [Quick sort v01]\n\n");
    print_vet(vet, len);
    quicksort_v01(vet, len);
    print_vet(vet, len);
    printf("*********************************************\n");
}

int main(){
    test_mergesort();
    test_quicksort_v01();

    return 0;
}
