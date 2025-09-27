// Bubble Sort Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_worst_arr(int arr[], int n) {
    for(int i=0;i<n;i++) arr[i]=n-i;
}

void bubbleSort(int arr[], int n) {
    int i,j,temp;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    gen_worst_arr(arr,n);

    clock_t end,start=clock();
    bubbleSort(arr,n);
    end=clock();

    double ms=((double)(end-start))/CLOCKS_PER_SEC*1000;
   printf("%.3f ms\n", time_taken_milli);

    free(arr);
    return 0;
}
