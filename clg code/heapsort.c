#include <stdio.h>

// Function to swap two integer values using pointers
void swap(int *x, int *y)
{
    int temp = *x; // Store the value at address x in temp
    *x = *y;       // Assign the value at address y to address x
    *y = temp;     // Assign temp (old x value) to address y
}

// Function to maintain the heap property at index 'i' in an array of size 'n'
void heapify(int arr[], int n, int i)
{
    int largest = i;   // Assume current node i is the largest
    int l = 2 * i + 1; // Index of left child in heap
    int r = 2 * i + 2; // Index of right child in heap

    // If left child exists and is greater than current largest
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child exists and is greater than current largest
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If the largest is not the current node, swap and continue heapifying
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]); // Swap parent with larger child
        heapify(arr, n, largest);     // Recursively heapify the affected subtree
    }
}

// Function to build a Max-Heap from an unsorted array
void buildMaxHeap(int arr[], int n)
{
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to find and print the top 'k' largest elements from the array
void findTopK(int arr[], int n, int k)
{
    buildMaxHeap(arr, n); // Convert the array into a max heap

    printf("Top %d largest elements: ", k);

    // Extract maximum element 'k' times
    for (int i = n - 1; i >= n - k; i--)
    {
        printf("%d ", arr[0]);  // Print the current maximum element
        swap(&arr[0], &arr[i]); // Move the max element to the end of the array
        heapify(arr, i, 0);     // Heapify the reduced heap
    }
}

int main()
{
    int arr[] = {3, 2, 1, 5, 6, 4};       // Input array
    int k = 2;                            // Number of top elements to find
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    findTopK(arr, n, k); // Call the function to print top k elements

    return 0; // End of program
}