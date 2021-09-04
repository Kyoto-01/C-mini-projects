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

void quicksort(){
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
    mergesort(nums, 0, nums_len - 1);
    print_vet(nums, nums_len);

    return 0;
}
