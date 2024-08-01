#include<stdio.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int strlength(int* A){
    int i = 0;
    while(A[i] != '\0'){
        i++;
    }
    return i;
}

void bubbleSort(int* A, int n){
    int i = 0;
    int j = 0;
    for(;i<n;i++){
        for(j = 0;j<n-i-1;j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int* A, int n){
    int i = 0;
    int j = 0;
    int isSorted = 0;
    for(;i<n;i++){
        isSorted = 1;
        printf("Working on pass number %d\n", i+1);
        for(j = 0;j<n-i-1;j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {3, 2, 1};
    printf("The array before sorting: ");
    printArray(A, 3);
    bubbleSortAdaptive(A, 3);
    printf("The array after sorting: ");
    printArray(A, 3);
    return 0;
}
