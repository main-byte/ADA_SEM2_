#include<stdio.h>
#include <stdlib.h>
#include <time.h>





int* gen_worst_arr(int size)
{
    int i;
    arr[size];
    for(i=0;i<size;i++){arr[i]=size-i;}


    return arr;
}

 int binarySearch(int arr[], int left, int right, int key)
 {
    while(left <=right){
        int mid = left +(right - left) /2;
        if(arr[mid] ==key){
            return mid;
        }
        
        else if(arr[mid]<key){
            left=mid+1;
        }

        else{
            right=mid-1;
        }
    }
    return -1;
 }
 
int main()
{
    clock_t start, end;
    double time_taken;
    int iterations = 100000;
    int n;
    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
     if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    //..............fill the array with random values
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    
    start= clock();
    
    for(int i=0;i<iterations;i++){
    int x= binarySearch(arr, 0 ,n-1, n); //.........worst case
    }

    end= clock();
    
    time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    double avg=(double)(time_taken/iterations)*1000;
    printf("Time taken for 100000 iterations is %lf msec (average per search)\n",avg);
    free(arr); 

    return 0;
}


