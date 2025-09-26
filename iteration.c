#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    int NOfTerms = atoi(argv[1]); 
    printf("NOfTerms:%d\n",NOfTerms);
    //check if  inputis not less than 1.
    bool check = false;
    while(check == false){
        if (NOfTerms < 1) {
            check = false;
            printf("enter valid value for no of terms!!.\n");
            scanf("enter no of terms you want to print: %d\n",&NOfTerms);
        }
        else{check = true;}
    }

    clock_t start, end;
    double time_taken_ms;

    start = clock();
    long a = 0, b = 1, next;
    for(int i = 1; i <= NOfTerms; i++){
        if(i == 1){
            printf("%ld, ", a);
        } else if(i == 2){
            printf("%ld, ", b);
        } else {
            next = a + b;
            printf("%ld, ", next);
            a = b;
            b = next;
        }
    }
    end = clock();
    time_taken_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("\ntime taken = %lf ms\n", time_taken_ms);

    return 0;
}