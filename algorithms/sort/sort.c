#include <stdio.h>


void mergesort(int* vet, int start, int end){
    // divide
    if(start >= end){
        return;
    }
    int mid = (start + end) / 2;
    mergesort(vet, start, mid);
    mergesort(vet, mid + 1, end);

    // create 2 sublists with left and right of the list
    int llen = mid - start + 1;
    int rlen = end - mid;
    int left[llen], right[rlen];

    for(int i = 0; i < llen; i++){
        left[i] = vet[start + i];
    }
    for(int i = 0; i < rlen; i++){
        right[i] = vet[mid + i + 1];
    }

    // merge
    int i = 0, j = 0, k = start;
    while(i < llen && j < rlen){
        if(left[i] <= right[j]){
            vet[k] = left[i];
            i++;
        }
        else{
            vet[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < llen){
        vet[k] = left[i];
        i++;
        k++;
    }
    while(j < rlen){
        vet[k] = right[j];
        j++;
        k++;
    }
}

void quicksort_v01(int *vet, int len){
    if(len < 2){
        return;
    }
    int pivot = vet[0];

    // * create 3 sublists with the less, equal and more than pivot elements *
    //  --> find the quantity of elements less, equal and more than pivot <--
    int qtd_less, qtd_equal, qtd_more;
    qtd_less = qtd_equal = qtd_more = 0;
    for(int i = 0; i < len; i++){
        if(vet[i] < pivot){
            qtd_less++;
        }
        else if(vet[i] > pivot){
            qtd_more++;
        }
        else{
            qtd_equal++;
        }
    }
    //  --> fill the sublists with less, equal and more tham pivot elements <--
    int less[qtd_less], equal[qtd_equal], more[qtd_more];
    int l, e, m;
    l = e = m = 0;
    for(int i = 0; i < len; i++){
        if(vet[i] < pivot){
            less[l] = vet[i];
            l++;
        }
        else if(vet[i] > pivot){
            more[m] = vet[i];
            m++;
        }
        else{
            equal[e] = vet[i];
            e++;
        }
    }
    quicksort_v01(less, qtd_less);
    quicksort_v01(more, qtd_more);

    int k = 0;
    for(int i = 0; i < qtd_less; i++){
        vet[k] = less[i];
        k++;
    }
    for(int i = 0; i < qtd_equal; i++){
        vet[k] = equal[i];
        k++;
    }
    for(int i = 0; i < qtd_more; i++){
        vet[k] = more[i];
        k++;
    }
}

void print_vet(int* vet, int len){
    for(int i = 0; i < len; i++){
        printf("%d; ", vet[i]);
    }
    printf("\n");
}

int main(){
    int nums[] = {1,5,2,4,1,0,3,0,0,5};
    int nums_len = sizeof(nums) / sizeof(nums[0]);

    print_vet(nums, nums_len);
    //mergesort(nums, 0, nums_len - 1);
    quicksort_v01(nums, nums_len - 1);
    print_vet(nums, nums_len);

    return 0;
}
