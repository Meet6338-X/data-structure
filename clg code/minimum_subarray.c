#include <stdio.h>

int smallestSubarrayLen(int arr[], int n, int k, int *res_start, int *res_end) 
{
    int start = 0, end = 0, curr_sum = 0;
    int min_len = n + 1;

    while (end < n) {
        curr_sum += arr[end];
        end++;

        while (curr_sum > k) {
            if (end - start < min_len) 
			{
                min_len = end - start;
                *res_start = start;
                *res_end   = end - 1; 
            }
            curr_sum -= arr[start];
            start++;
        }
    }
    return (min_len == n + 1) ? 0 : min_len;
}

int main() 
{
    int arr[] = {1, 4, 45, 6, 0, 19},n = sizeof(arr) / sizeof(arr[0]),k = 51;
    int res_start = -1, res_end = -1;
    int result = smallestSubarrayLen(arr, n, k, &res_start, &res_end);

    if (result == 0) 
	{
        printf("No subarray found\n");
    }
	else 
	{
        printf("Smallest subarray length = %d\n", result);
        printf("Subarray: ");
        for (int i = res_start; i <= res_end; i++) 
		{
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}