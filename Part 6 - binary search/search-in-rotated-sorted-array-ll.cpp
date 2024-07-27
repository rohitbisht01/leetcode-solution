#include <bits/stdc++.h>
using namespace std;

// check if a target element is present in the rotated sorted array
// similar to search in a rotated sorted array except we have duplicates here
// approach
// same as search in a sorted rotated array + need to write logic for handling or skipping duplicate elements

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        // avoid duplicates
        while (low < high && nums[low] == nums[low + 1])
            low++;
        while (low < high && nums[high] == nums[high - 1])
            high--;

        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;

        if (nums[mid] >= nums[low])
        { // left half sorted
            if (target >= nums[low] && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        { // right half sorted
            if (target <= nums[high] && target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return false;
}

int main()
{
    return 0;
}