#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int low, int mid, int high)
{
    int n = high - low + 1;
    int *temp = (int *)malloc(n * sizeof(int)); // temporary array

    int left = low;      // starting index of left half
    int right = mid + 1; // starting index of right half
    int k = 0;           // index for temp

    // Merging in sorted order
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            temp[k++] = arr[right++];
        }
    }

    // Copy remaining elements of left half
    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }

    // Copy remaining elements of right half
    while (right <= high)
    {
        temp[k++] = arr[right++];
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
    {
        arr[low + i] = temp[i];
    }

    free(temp); // free allocated memory
}

// Merge Sort function
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merge sorted halves
}

int main()
{
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("After Sorting Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
