#include <bits/stdc++.h>
using namespace std;

// to aoid integer overflow
// int mid = low + (high-low)/2;  OR
// int mid = high - (high-low)/2;

// T(N) => O(log N)
// S(N) => O(1)

int binarySearchIterative(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binaryRecursive(int low, int high, vector<int> &nums, int target)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            return binaryRecursive(mid + 1, high, nums, target);
        else
            return binaryRecursive(low, mid - 1, nums, target);
    }
    return -1;
}

int main()
{
    vector<int> nums = {2, 3, 5, 7, 9};
    int target = 7;
    cout << binarySearchIterative(nums, target) << endl;
    cout << binaryRecursive(0, nums.size(), nums, target) << endl;
    return 0;
}