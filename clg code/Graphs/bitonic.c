// #include<stdio.h>

// void bruteForceApproach(int arr[], int n)
// {
//     int longestLength = 0,tempLength = 0,start = -1,end = -1;

//     for(int i = 0; i < n; i++)
//     {
//         int left = i - 1;
//         int right = i + 1;

//         while(left >= 0 && arr[left] <= arr[left + 1])
//         {
//             left--;
//         }

//         while(right <= n - 1 && arr[right] <= arr[right - 1])
//         {
//             right++;
//         }
//         left++;
//         right--;

//         tempLength = right - left + 1;
//         if(tempLength > longestLength)
//         {
//             start = left;
//             end = right;
//             longestLength = tempLength;
//         }
//     }

//     printf("bruteforce approach : \n");
//     if(start == -1 && end == -1)
//     {
//         printf("no bitonic subarray found\n");
//     }
//     else
//     {
//         if(start == -1)
//         {
//             start = 0;
//         }
//         if(end == -1)
//         {
//             end = n - 1;
//         }

//         printf("longest bitonic array length : %d\n", longestLength);
//         printf("longest biotonic subarray : \n");
        
//         printf("[");
        
//         for(int i = start; i <= end; i++)
//         {
//             printf(" %d", arr[i]);
//         }
        
//         printf(" ]\n");
//     }

// }

// void optimalApproach(int arr[], int n)
// {
//     int maxLength = 0,inc[n],dec[n],start  = -1,end = -1;
//     inc[0] = 1;
//     dec[n - 1] = 1;

//     for(int i = 1; i < n; i++)
//     {
//         inc[i] = (arr[i] >= arr[i - 1]) ? inc[i-1] + 1 : 1;
//     }

//     for(int j = n - 2; j >= 0; j--)
//     {
//         dec[j] = ( arr[j] >= arr[j + 1]) ? dec[j + 1] + 1 : 1;
//     }

//     for(int i = 0; i < n; i++)
//     {
//         int currLength = inc[i] + dec[i] - 1;
//         if(currLength > maxLength)
//         {
//             start = i - inc[i] + 1;
//             end = i + dec[i] - 1;
//             maxLength = currLength;
//         }
//     }


//     printf("optimal approach : \n");

//     if(start == -1 && end == -1)
//     {
//         printf("no bitonic subarray found\n");
//     }
//     else{
//         if(start < 0)
//         {
//             start = 0;
//         }
    
//         printf("longest bitonic array length : %d\n", maxLength);
//         printf("longest biotonic subarray : \n");
        
//         printf("[");
        
//         for(int i = start; i <= end; i++)
//         {
//             printf(" %d", arr[i]);
//         }
        
//         printf(" ]\n");
//     }

// }

// int main(){
//     int arr[] = {12, 4, 78, 90, 45, 23};
//     int n = sizeof(arr) / sizeof(int);

//     bruteForceApproach(arr, n);
//     printf("\n\n");
//     optimalApproach(arr, n);
//     return 0;
// }

#include<stdio.h>
int bitonic_subarray(int arr[], int n, int *start, int *end, int *peak)
{
    int inc[n], dec[n], maxlen;

    inc[0]=1;
    for(int i=1; i<n; i++)
    {
        inc[i] = (arr[i]>arr[i-1]) ? inc[i-1]+1 : 1;
    }

    dec[n-1]=1;
    for(int i=n-2; i>=0; i--)
    {
        dec[i] = (arr[i] > arr[i+1]) ? dec[i+1]+1 : 1;
    }
    
    *peak = 0;
    maxlen=1;
    for(int i=0; i<n; i++)
    {
        int len = inc[i] + dec[i] -1;
        if(len > maxlen)
        {
            maxlen = len;
            *peak = i;
        }
    }

    *start = *peak - (inc[*peak] - 1);
    *end = *peak +(dec[*peak] -1);
    return maxlen;
}

int main()
{
    int arr[]={8,12,4,78,90,45,23,11,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start, end, peak, len;
    len = bitonic_subarray(arr, n, &start, &end, &peak);
    printf("Length = %d",len);
    printf("\nPeak = %d at index = %d", arr[peak], peak);
    printf("\nSubarray = ");
    for(int i=start; i<=end; i++)
    {
        printf("%d ",arr[i]);
    }
}