#include <bits/stdc++.h>
using namespace std;

// brute force => linear search and update minimum
// T(N) => O(N)
// S(N) => O(1)
int findMin(vector<int> &nums)
{
    int mini = INT_MAX;
    for (int num : nums)
    {
        mini = min(mini, num);
    }
    return mini;
}

// binary search
// T(N) => O(log n)
// S(N) => O(1)

// int findMin(vector<int> &nums)
// {
//     int n = nums.size();
//     int low = 0, high = n - 1;
//     int mini = INT_MAX;
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (nums[low] > nums[high] && nums[high] < nums[mid])
//         {
//             mini = min(mini, nums[mid]);
//             low = mid + 1;
//         }
//         else
//         {
//             mini = min(mini, nums[mid]);
//             high = mid - 1;
//         }
//     }
//     return mini;
// }

// During each iteration, we will select the leftmost element from the sorted half and discard that half from further consideration. Among all the selected elements, the minimum value will serve as our answer.
int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int mini = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[mid]) // left half is sorted
        {
            mini = min(mini, nums[low]);
            low = mid + 1;
        }
        else // right half is sorted
        {
            mini = min(mini, nums[mid]);
            high = mid - 1;
        }
    }
    return mini;
}

// further optimization on binary search
int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int mini = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[high])
        {
            mini = min(mini, nums[low]);
            break;
        }

        if (nums[low] <= nums[mid]) // left half is sorted
        {
            mini = min(mini, nums[low]);
            low = mid + 1;
        }
        else // right half is sorted
        {
            mini = min(mini, nums[mid]);
            high = mid - 1;
        }
    }
    return mini;
}

int main()
{
    return 0;
}