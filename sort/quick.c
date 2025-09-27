#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

//switch function
void snitch(int*a,int*b){int temp = *b;*b = *a;*a = temp;}

//copy function of array.
int* copy_arr(int*arr,int size){
    int *copied_arr = (int*)malloc(size * sizeof(int));
    for(int i =0; i<size; i++)copied_arr[i] = arr[i];
    return copied_arr;
}




int* gen_worst_arr(int size)
{
    int i;
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; // Exit with an error code
    }
    for(i=0;i<size;i++){arr[i]=size-i;/*printf("%d ",array[i];*/}
    printf("\n");
    


    return arr;
    
}


// Partition function for quicksort using middle pivot
int partition(int* array, int low, int high) {
    int pivot_i = low + (high - low) / 2;
    int pivot = array[pivot_i];
     snitch (&array[pivot_i], &array[high]); // Move pivot to end
    int store = low;
    for (int i = low; i < high; i++){
        if (array[i] < pivot) {
            snitch(&array[i] , &array[store]);
            store++;
        }
    }
    snitch(&array[store], &array[high]); // Move pivot to its final place
    return store;
}

// Quicksort function
void quicksort(int* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        // printf("--pi:%d--",pi);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

//main function
int main()

{
    
    clock_t start,end;
    clock_t c_start,c_end;
    
    int test_index;
    int size=0,i=0;
    
    printf("Enter size of array from following :\n");
    scanf("%d", &size);

    int* array ;
    array = gen_worst_arr(size);
    
    int* working_array = copy_arr(array,size);
  
    

    start=clock();
    quicksort(working_array,0,size-1);
    end=clock();
    double time_taken_milli = ((double)(end-start))/CLOCKS_PER_SEC*1000;
    printf("Time taken by Quick Sort = %f ms\n", time_taken_milli);

}
