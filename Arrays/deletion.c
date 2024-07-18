// Performing deletion on array element without changing the array order

#include<stdio.h>

// Deletion method for array
int index_deletion(int arr[], int size, int index, int capacity){
    if(index>=size){
        return -1; // failed to delete the element as array is empty or index not valid
    }
    for (int i = index; i<=(size-2) ; i++){
        arr[i] = arr[i+1];
    }
    return 1; // deletion successful
}

// Traversal method for array
void show(int arr[], int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int index; //index of element to be deleted
    int size = 8; // size being used in array
    int capacity = 100; // total size of array
    int arr[100] = {1, 5, 10, 78, 22, 98, 100, 101};
    int result;
    show(arr, size);
    printf("Enter the index of element you want to delete : ");
    scanf("%d", &index);
    result = index_deletion(arr, size, index, capacity);
    if(result == 1){
        size -= 1;
    } else if(result == -1){
        printf("Invalid input! Deletion failed! \n");
    }
    
    show(arr, size);

    return 0;
}