// Insertion Sort Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to create worst case array (descending order)
void gen_worst_arr(int arr[], int n) {
    for(int i=0;i<n;i++) {
        arr[i] = n - i;
    }
}

// insertion sort
void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i=1;i<n;i++) {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key) {

            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n * sizeof(int));
    gen_worst_arr(arr,n);

    clock_t start = clock();
    insertion_sort(arr,n);
    clock_t end = clock();

    double time_taken_milli = ((double)(end-start))/CLOCKS_PER_SEC*1000;
    printf("%.3f ms\n", time_taken_milli);

    free(arr);
    return 0;
}
