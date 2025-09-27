#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int linearSearch(int arr[], int n, int key) 
{
 for (int i = 0; i < n; i++) {
       if (arr[i] == key)
       return i;
}
   
    return -1;
}
   
int main() 
{


       int n, key, iteration = 10000;
       clock_t start, end;
       double time_taken;


       printf("Enter number of elements (n): \n");
       scanf("%d", &n);
     
       int *arr = (int *)malloc(n * sizeof(int));
       for (int i = 0; i < n; i++){
        arr[i] = i + 1;
     }
   
      key = n; // worst case
   
      start = clock();
 
      for(int i = 0; i < iteration; i++) {
      linearSearch(arr, n, key);
    }
     
      end = clock();
   
    //time
      time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
     
     //average time per search in milliseconds
     
      double avg = (time_taken / iteration)*1000;
      printf("Time taken: %lf msec\n",avg);
   
      free(arr);


    return 0;
}
