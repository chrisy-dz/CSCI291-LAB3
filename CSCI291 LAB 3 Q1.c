// Including library headers for the working of the code
#include <stdio.h>
#include <stdbool.h>

// Function to check if a position is within valid range of array indices
bool isValid(const int arr[], int length, int pos) {
    return (pos >= 0 && pos < length);
}

// Function to remove an element at a given position by shifting elements down
void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Invalid position %d. Cannot remove element.\n", pos);
        return; // Exiting the function on invalid position
    }
    
    // Using for loop
    for (int i = pos; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
}

// Function to insert an element at a given position by shifting elements up
void insert_element(int arr[], int length, int pos, int value) {
    if (!isValid(arr, length, pos)) {
        printf("Invalid position %d. Cannot insert element.\n", pos);
        return; // Exiting the function on invalid position
    }
    
    // Shift elements up from position 
    for (int i = 0; i < pos; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Inserting the new value 
    arr[pos] = value;
}


// Function to reshape a 1D array into a 2D array
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]) 
{
    // Using if statement
    if (length != nRows * nCols) {
        printf("Error: Array length does not match dimensions %d x %d.\n", nRows, nCols);
        return; // Exiting the function if dimensions do not match
    }
    
    int index = 0;
    // Using nested for loop
    for (int col = 0; col < nCols; col++) {
        for (int row = 0; row < nRows; row++) {
            arr2d[row][col] = arr[index++];
        }
    }
}

// Function to transpose a matrix
void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat_transp[nCols][nRows]) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            mat_transp[j][i] = mat[i][j];
        }
    }
}

// Function to check if there are any duplicate values
bool found_duplicate(int arr[], int length) 
{
    // using nested for loop
    for (int i = 0; i < length - 1; i++) 
    {
        for (int j = i + 1; j < length; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                return true;
            }
        }
    }
    return false;
}

// Function to print a 1D array for testing
void printArray(const int arr[], int length) 
{
    for (int i = 0; i < length; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print a 2D array for testing
void print2DArray(int nRows, int nCols, int arr2d[nRows][nCols]) 
{
    for (int i = 0; i < nRows; i++) 
    {
        for (int j = 0; j < nCols; j++) 
        {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }
}

// Main function to test 
int main() 
{
    // Test values
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, length);

    // Test remove element
    printf("\nRemoving element at index 2:\n");
    remove_element(arr, length, 2);
    printArray(arr, length);

    // Test removing element with invalid index
    printf("\nAttempting to remove element at index 10:\n");
    remove_element(arr, length, 10);

    // Reset array for insertion test
    int arr2[] = {10, 20, 30, 40, 50};
    printf("\nInserting 80 at index 2:\n");
    insert_element(arr2, length, 2, 80);
    printArray(arr2, length);

    // Test inserting element with invalid index
    printf("\nAttempting to insert at index 10:\n");
    insert_element(arr2, length, 10, 80);

    // Test reshape function
    int nRows = 3, nCols = 2;
    int arr3[] = {1, 2, 3, 4, 5, 6};
    int arr2d[3][2];
    printf("\nReshaping 1D array to 3x2 2D array:\n");
    reshape(arr3, 6, nRows, nCols, arr2d);
    print2DArray(nRows, nCols, arr2d);

    // Test reshape function with invalid dimensions
    printf("\nAttempting to reshape 1D array to incompatible dimensions 2x2:\n");
    reshape(arr3, 6, 2, 2, arr2d);

    // Test transpose matrix 
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int mat_transp[3][2];
    printf("\nOriginal matrix:\n");
    print2DArray(2, 3, mat);
    trans_matrix(2, 3, mat, mat_transp);
    printf("\nTransposed matrix:\n");
    print2DArray(3, 2, mat_transp);

    // Test for finding duplicates 
    int arr4[] = {10, 20, 30, 20, 50};
    printf("\nChecking for duplicates in array:\n");
    printArray(arr4, 5);
    if (found_duplicate(arr4, 5)) {
        printf("Duplicates found.\n");
    } else {
        printf("No duplicates found.\n");
    }

    return 0;
}
