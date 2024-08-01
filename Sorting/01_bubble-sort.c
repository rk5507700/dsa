#include<stdio.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
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

int main(int argc, char const *argv[])
{
    int A[] = {23, 20, 12, 9, 7, 6, 5, 4};
    printf("The array before sorting: ");
    printArray(A, 6);
    bubbleSort(A, 6);
    printf("The array after sorting: ");
    printArray(A, 6);
    return 0;
}
