#include <bits/stdc++.h>
using namespace std;

// brute force
// just do a linear search
// T(N) => O(N)
// S(N) => O(1)

int Search(vector<int> &vec, int K)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == K)
            return i;
    }
    return -1;
}

// binary search
// T(N) => O(log N)
// S(N) => O(1)

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] >= nums[low])
        { // left half is sorted
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        { // right half is sorted
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int target = 10;

    cout << search(nums, target);
    cout << endl;
    cout << Search(nums, target);
    cout << endl;

    return 0;
}