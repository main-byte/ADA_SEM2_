#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

long fibo(int n,long* fib,int* indexPtr,int nfirst);

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


int index = 0 ; //tells no of elements in fib array 
int* indexPtr = &index; 

long* ptr = (long*)malloc(NOfTerms * sizeof(long));
clock_t start, end;
long double time_taken_ms;

int i = 1;
    start = clock();
    while(i <= NOfTerms){
        printf("%ld, ",fibo(NOfTerms,ptr,indexPtr,NOfTerms) );
        i++;

    }
    end = clock();
    time_taken_ms = ((end - start)*1000000)/CLOCKS_PER_SEC; 
    printf("\ntime taken in 10^-6 s= @%Lf\n", time_taken_ms);






free(indexPtr);
free(ptr);
}


long fibo(int n,long* fib,int* indexPtr,int nfirst){
    int k = *indexPtr;
    int i = 0;
    switch(n){
    case 1: 
    return 0; 
    case 2: 
    return 1; 
    default:
    //check and add  in fib array.
        
            if (k+2 == nfirst){
                return fib[n-1] ;
            }
            else{
                *indexPtr+=1; 
                fib[k] = fibo(n-1,fib,indexPtr,nfirst) + fibo(n-2,fib,indexPtr,nfirst);
                return fib[k];      
            }
       
    }



}