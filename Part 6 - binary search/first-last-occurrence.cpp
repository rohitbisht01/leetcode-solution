#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(N + N) => O(N)
// S(N) => O(1)
vector<int> indexes(vector<int> nums, int target)
{
    int firstOcc = -1, lastOcc = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            firstOcc = i;
            break;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            lastOcc = i;
        }
    }

    return {firstOcc, lastOcc};
}

// using binary search

// T(N) => O(log N)
// S(N) => O(1)
vector<int> searchRange(vector<int> &nums, int target)
{

    int firstOcc = -1, lastOcc = -1;
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            firstOcc = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            lastOcc = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return {firstOcc, lastOcc};
}

// using built in functions like upper_bound and lower_bound
// T(N) => O(N)
// S(N) => O(N)
// void findFirstAndLast(vector<int> &nums, int target)
void findFirstAndLast(int nums[], int n, int target)
{
    // int n = nums.size();
    // Convert iterators to indices
    // auto firstIt = lower_bound(nums.begin(), nums.end(), target);
    // auto lastIt = upper_bound(nums.begin(), nums.end(), target);

    int firstIt = lower_bound(nums, nums + n, target) - nums;
    int lastIt = upper_bound(nums, nums + n, target) - nums - 1;

    // int firstOcc = (firstIt != nums.end() && *firstIt == target) ? distance(nums.begin(), firstIt) : -1;
    // int lastOcc = (lastIt != nums.begin() && *(lastIt - 1) == target) ? distance(nums.begin(), lastIt) - 1 : -1;

    // cout << firstOcc << " " << lastOcc << endl;
    cout << firstIt << " " << lastIt << endl;
}

int main()
{
    vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int target = 5;
    vector<int> ans = indexes(nums, target);

    for (int num : ans)
        cout << num << " ";
    cout << endl;

    ans = searchRange(nums, target);

    for (int num : ans)
        cout << num << " ";
    cout << endl;

    // findFirstAndLast(nums, target);
    int nums[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(nums) / sizeof(nums[0]);
    findFirstAndLast(nums, n, target);
    return 0;
}