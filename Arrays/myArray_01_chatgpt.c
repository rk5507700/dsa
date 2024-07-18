#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Ask the user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Allocate memory for the character array
    char *array = (char *)malloc(n * sizeof(char));
    
    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Initialize the array with some values for demonstration
    for (int i = 0; i < n; i++) {
        array[i] = 'A' + (i % 26);  // Just filling it with some letters
    }
    
    // Print the array
    printf("The character array is: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", array[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(array);
    
    return 0;
}
