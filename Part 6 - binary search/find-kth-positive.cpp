#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(N * N)
// S(N) => O(1)
int findKthPositive(vector<int> &arr, int k)
{
    int current = 1;
    int missingPositive = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        while (current < arr[i])
        {
            missingPositive++;
            if (missingPositive == k)
            {
                return current;
            }
            current++;
        }
        current++;
    }

    // if the k th missing number is beyond the max number
    while (missingPositive < k)
    {
        missingPositive++;
        if (missingPositive == k)
        {
            return current;
        }
        current++;
    }
    return -1;
}

// using binary search
// T(N) => O(log N)
// S(N) => O(1)
int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1;
}