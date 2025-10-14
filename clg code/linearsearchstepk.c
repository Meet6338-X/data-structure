#include <stdio.h>
int linearSearchWithStep(int arr[], int n, int target, int step)
{
    if (step <= 0)
    {
        step = 1; // Validate step size
    }
    int i = 0;
    // Step-wise forward search
    for (i = 0; i < n && arr[i] < target; i += step)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    // If target is larger than the last element, it's not present
    if (i >= n && arr[n - 1] < target)
    {
        return -1;
    }
    // Adjust i if we jumped past array bounds
    if (i >= n)
    {
        i = n - 1;
    }
    // Reverse linear search in skipped block
    for (; i >= 0; i--)
    {
        if (arr[i] == target)
        {
            return i;
        } // Stop early if arr[i] < target (array is sorted)
        if (arr[i] < target)
        {
            break;
        }
    }
    return -1; // Not found
}

int main()
{
    int arr[] = {1, 2, 4, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target, step;
    // Input target element
    printf("Enter the element you want to search: ");
    scanf("%d", &target);
    // Input step size
    printf("Enter step size: ");
    scanf("%d", &step);
    if (step <= 0)
    {
        printf("Invalid step size. Using step = 1.\n");
        step = 1;
    }
    // Perform search
    int index = linearSearchWithStep(arr, n, target, step);
    if (index != -1)
    {
        printf("Element %d found at index %d\n", target, index);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }
    return 0;
}
