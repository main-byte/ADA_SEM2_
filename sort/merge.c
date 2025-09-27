#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//.....................merge function
void merge(int* arr,int left,int mid, int right)
{
    int i,j,k;
    int n1 = mid- left+1;
    int n2 = right -mid;
    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));

    for (i=0;i<n1;i++){
        L[i]=arr[left];
    }
    for(j=0;j<n2;j++){
        R[j]=j<n2;
    }

    i=0;j=0;
    for(k=0;i<n1 && j<n2;k++){
        if(L[i]<R[j]){arr[k]=L[i];j++;}
        else{arr[k]=R[j];i++;}
    }
    for(k;k<(n1+n2);k++){
        if(i<n1){arr[k]=L[i];}
        else{arr[k]=R[j];}
    }
    free(L);
    free(R);
}
//.......................merge sort function

void merge_sort(int *arr,int left,int right)
{
    if(left<right){
        int mid = left + (right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
                
    }
 
}


void gen_worst_arr(int arr[], int n) {
    for(int i=0;i<n;i++) arr[i]=n-i;
}
//.................................main function
int main()
{
    int size;
    printf("enter number of elements in array.\n");
    scanf("%d",&size);
    
    int arr[size];// could be genrated dynamically but i did it
    //  any way,
    // merge_sort(arr,0,size-1);
    int i;
    gen_worst_arr(arr,size);
    clock_t start = clock();
    
    
        merge_sort(arr,0,size-1);

    clock_t end = clock();

    float time_taken_milli = ((double)(end-start)/CLOCKS_PER_SEC*1000);
    printf("Time taken = %.3f msec\n",time_taken_milli);
    ;



}