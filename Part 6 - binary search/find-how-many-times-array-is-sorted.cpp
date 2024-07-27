#include <bits/stdc++.h>
using namespace std;

// We can easily observe that the number of rotations in an array is equal to the index(0-based index) of its minimum element.
// So, in order to solve this problem, we have to find the index of the minimum element.

// brute force => find the mini element and the index of min element by iterating over the array
// T(N) => O(N)
// S(N) => O(1)
int findKRotation(vector<int> &arr)
{
    int n = arr.size(); // size of array.
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < ans)
        {
            ans = arr[i];
            index = i;
        }
    }
    return index;
}

// using binary search
// T(N) => O(log n)
// S(N) => O(1)
int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    return 0;
}