#include <bits/stdc++.h>
using namespace std;

// brute force => simple linear search approach
// T(N) => O(N)
// S(N) => O(1)

// binary search
// T(N) => O(log N)
// S(N) => O(1)
pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int ceilEle = -1;
    int floorEle = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)
        {
            floorEle = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            ceilEle = arr[mid];
            high = mid - 1;
        }
    }
    return make_pair(floorEle, ceilEle);
}

int main()
{
    int arr[] = {5, 6, 8, 9, 6, 5, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    pair<int, int> ans = getFloorAndCeil(arr, n, x);
    cout << "Floor: " << ans.first << ", Ceil: " << ans.second << endl;
    return 0;
}