#include <stdio.h>

void printArray(int arr[], int n)
{
    printf("Contents of array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int pivot(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    int pivotElement = arr[mid];

    arr[mid] = arr[low];
    arr[low] = pivotElement;

    int i = 0;
    int j = high;

    while (i < j)
    {
        while (i < high && arr[i] <= pivotElement)
        {
            i++;
        }
        while (j > low && arr[j] > pivotElement)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivotElement;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivotIndex = pivot(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

int main()
{
    int arr[] = {3, 5, 1, 2, 4};
    int n = sizeof(arr) / sizeof(int);
    printf("Before sorting : \n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("After sorting : \n");
    printArray(arr, n);
    return 0;
}