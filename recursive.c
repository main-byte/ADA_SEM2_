#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

long fib(int n);

int main(int argc, char* argv[]){
    

       int NOfTerms = atoi(argv[1]); 
    printf("NOfTerms:%d\n",NOfTerms);
    //check if  inputis not less than 1.
    bool check = false;
    while(check == false){
        if (NOfTerms < 1) {
            
            printf("enter valid value for no of terms!!.\n");
            scanf("%d",&NOfTerms);
        }
        else{check = true;}
    }

    // scanf("enter no of terms you want to print.\n",&NOfTerms);
    clock_t start,end;  
    double time_taken_ms;

    int i = 1;
    start = clock();
    while(i <= NOfTerms){
        printf("%ld, ",fib(i) );
        i++;

    }
    end = clock();
    time_taken_ms = (end - start)/CLOCKS_PER_SEC *1000 ; 
    printf("\ntime taken = @%lf", time_taken_ms);

    

    return 0;
}

long fib(int n){

    switch(n){
    case 1: 
    return 0; 
    case 2: 
    return 1; 
    default:
    return fib(n-1)  + fib(n-2);
    }



}