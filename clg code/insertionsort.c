#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort Function
void insertion_sort(int arr[], int n)
{
    int counter = 0;

    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(&arr[j - 1], &arr[j]);
            counter++;
            j--;
        }

        // Display array after each pass
        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    // Final sorted array
    printf("\nFinal Answer: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Total shifts
    printf("Total Shifts: %d\n", counter);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    return 0;
}
