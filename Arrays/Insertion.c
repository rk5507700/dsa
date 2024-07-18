//Insertion in array

#include<stdio.h>

int index_Insertion(int arr[], int index, int element, int size, int capacity){
    if(size>=capacity){
        return -1; //failed to insert the element
    }

    for(int i = (size-1); i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;

}

// Traversal of array
void show(int arr[], int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int index/* index in array where element is to be inserted*/;
    int element/*The element that is to be inserted*/;
    int size = 5;// size that is being used in array 
    int capacity = 100; //Total size of the array
    int arr[100] = {1, 2, 6, 7, 10};
    int result = 0;

    show(arr, size);

    printf("Enter the index and element : ");
    scanf("%d %d", &index, &element);

    result = index_Insertion(arr, index, element, size, capacity);
    if(result == 1){
        size += 1;
    }
    show(arr, size);

    return 0;
}