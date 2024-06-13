#include <bits/stdc++.h>
using namespace std;

// T(N) => O( log N )
// S(N) => O(1)

// iterative binary search
int binarySearch(int arr[], int n, int target)
{
    int low = 0, right = n - 1;
    while (low <= right)
    {
        int mid = (low + right) / 2;
        if (arr[mid] == target)
            return mid + 1;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// recursive binary search
int recursiveBinarySearch(int arr[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid + 1;

        if (arr[mid] < target)
            return recursiveBinarySearch(arr, mid + 1, high, target);
        else
            return recursiveBinarySearch(arr, low, mid - 1, target);
    }
    return -1;
}

int main()
{
    int n = 10;
    int arr[n] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 91;
    cout << binarySearch(arr, n, target) << endl;
    cout << recursiveBinarySearch(arr, 0, n - 1, target) << endl;
    return 0;
}