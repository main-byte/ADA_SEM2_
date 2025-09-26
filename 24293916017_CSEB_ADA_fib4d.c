#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    int NOfTerms;
    if(argc > 1){
        NOfTerms = atoi(argv[1]);
        printf("NOfTerms:%d\n",NOfTerms);
    } else {
        printf("enter no of terms you want to print: ");
        scanf("%d", &NOfTerms);
    }

    bool check = false;
    while(check == false){
        if (NOfTerms < 1) {
            printf("enter valid value for no of terms!!.\n");
            printf("enter no of terms you want to print: ");
            scanf("%d", &NOfTerms);
        }
        else{check = true;}
    }

    long long* fib_table = (long long*)malloc(NOfTerms * sizeof(long long));
    if (fib_table == NULL) {
        printf("Error: Failed to allocate memory for the DP table.\n");
        return 1;
    }

    clock_t start, end;
    long double time_taken_us;

    start = clock();
    // Fill Fibonacci table iteratively
    if (NOfTerms >= 1) fib_table[0] = 0;
    if (NOfTerms >= 2) fib_table[1] = 1;
    for(int i = 2; i < NOfTerms; i++){
        fib_table[i] = fib_table[i-1] + fib_table[i-2];
    }
    end = clock();

    time_taken_us = ((end - start) * 1000000.0) / CLOCKS_PER_SEC;

    // Print sequence
    for(int i = 0; i < NOfTerms; i++){
        printf("%lld", fib_table[i]);
        if(i < NOfTerms - 1) printf(", ");
    }
    printf("\ntime taken in 10^-6 s= @%Lf\n", time_taken_us);

    free(fib_table);
    return 0;
}

