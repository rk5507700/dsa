#include<stdio.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int strlength(int A[]){
    int i = 0;
    while(A[i] != '\0'){
        i++;
    }
    return i;
}

void insertionSort(int* A, int n){
    int i = 1, key, j;
    for(;i <=n-1;i++){
        key = A[i];
        j = i-1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        if(j >= 0)
            A[j+1] = key;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 4, 5, 7, 90, 58, 70}; 
    int n = 7;

    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
