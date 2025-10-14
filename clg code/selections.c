#include <stdio.h>
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        // Swap arr[i] and arr[mini]
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }

    // Print array after sorting
    printf("After selection sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Print array before sorting
    printf("Before selection sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    selection_sort(arr, n);
    return 0;
}