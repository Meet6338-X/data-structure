#include <stdio.h>

// Function to find first occurrence of key in sorted array
int firstOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            first = mid;
            high = mid - 1; // Search left side
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

// Function to find last occurrence of key in sorted array
int lastOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            last = mid;
            low = mid + 1; // Search right side
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

// Function to count occurrences of key
int countOccurrences(int arr[], int n, int key)
{
    int first = firstOccurrence(arr, n, key);
    if (first == -1)
        return 0; // Not found
    int last = lastOccurrence(arr, n, key);
    return (last - first + 1);
}

int main()
{
    int arr[] = {1, 2, 4, 6, 8, 13, 19, 19, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 19;

    int count = countOccurrences(arr, n, key);
    printf("The number of occurrences of %d is: %d\n", key, count);

    return 0;
}