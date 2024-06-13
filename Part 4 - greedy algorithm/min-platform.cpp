#include <bits/stdc++.h>
using namespace std;

// T(N) => O(N * N)
// S(N) => O(1)

int countPlatforms(int n, int arr[], int dep[])
{
    int ans = 1; // final value
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1; // count of overlapping interval of only this   iteration
        for (int j = i + 1; j <= n - 1; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++;
            }
        }
        ans = max(ans, count); // updating the value
    }
    return ans;
}

// efficient=> sorting
// T(N) => O( n log n )
// S(N) => O(1)

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);

    int maxplatform = 1;
    int cnt = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        maxplatform = max(maxplatform, cnt);
    }
    return maxplatform;
}