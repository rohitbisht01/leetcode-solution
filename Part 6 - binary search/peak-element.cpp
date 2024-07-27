#include <bits/stdc++.h>
using namespace std;

// brute force => traverse the array and check for element which is greater or equal to adjacent elements
// edge case => single element, arr[0] >= arr[1] and arr[n-1] >= arr[n-2]
// T(N) => O(N)
// S(N) => O(1)

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] >= nums[1])
        return 0;
    if (nums[n - 1] >= nums[n - 2])
        return n - 1;

    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1])
            return i;
    }

    return -1;
}

// use binary search
// edge case => single element, arr[0] >= arr[1] and arr[n-1] >= arr[n-2]
// now start from 1st index till n-2 th index
// T(N) => O(log n)
// S(N) => O(1)

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low = 1, high = n - 2;
    if (n == 1)
        return 0;
    if (nums[0] >= nums[1])
        return 0;
    if (nums[n - 1] >= nums[n - 2])
        return n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= nums[mid - 1] && nums[mid] >= nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] < nums[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement(nums) << endl;
    return 0;
}