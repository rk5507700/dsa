// Searching in array for element using linear search
#include<stdio.h>

// Traversal method for array
void show(int arr[], int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// linear search method for arrays
// Traversal method for array
int linear_search(int arr[], int element, int size){
    for(int i = 0; i<size; i++){
        if(element == arr[i]){
            return i;
        }
    }
    printf("\n");
    return -1;
}

int main(){
    int element;
    int index;
    int size = 8;
    int arr[100] = {1, 56, 79, 45, 33, 23, 101, 304};
    printf("Enter the element you want to search : ");
    scanf("%d", &element);
    show(arr, size);
    index = linear_search(arr, element, size);
    if(index == -1){
        printf("Element not found!");
    } else {
        printf("Your element is at index %d or at position %d", index, index+1);
    }

    return 0;

}