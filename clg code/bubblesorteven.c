#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int passes = n / 2;
    for (int p = 0; p < passes; p++)
    {
        for (int j = 0; j <= n - 3; j += 2)
        {
            if (arr[j] > arr[j + 2])
            {
                int temp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = temp;
            }
        }

        printf("Array after pass %d: ", p + 1);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    printf("Final array after sorting even-indexed comparison:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}