#include<stdio.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int* a, int size_of_array){
    int i = 0 ;
    int min_index = 0;
    int min = a[min_index];
    for(i = 0;i<size_of_array;i++){
        min = a[i];
        min_index = i;
        for(int j = i+1; j < size_of_array; j++){
            if(a[j] < min)
                min_index = j;
                min = a[min_index];
        }
        a[min_index] = a[i];
        a[i] = min; 
    }
}

// int arraySize(int* arr){
//     int i = 0;
//     while(arr[i] != 0){
//         i++;
//     }
//     return i;
// }

int main(int argc, char const *argv[])
{   
    int arr[] = {30, 70, 58, 64, 34};

    printArray(arr, 5);
    selectionSort(arr, 5);
    printArray(arr, 5);
    
    return 0;
}


