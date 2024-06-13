#include <bits/stdc++.h>
using namespace std;

// sorting
// T(N) => O(N log N + N)
// S(N) => O(1)
int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == nums[i])
        {
            return nums[i];
        }
    }
    return -1;
}

// using frequency array
// T(N) => O(N)
// S(N) => O(N)
int findDuplicateElement(vector<int> &nums)
{
    int n = nums.size();
    int freq[n + 1] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[nums[i]] == 0)
            freq[nums[i]] += 1;
        else
            return nums[i];
    }
    return -1;
}

// slow and fast pointer approach
// T(N) => O(N)
// S(N) => O(1)
int slowFastApproach(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};
    cout << findDuplicate(nums) << endl;
    cout << findDuplicateElement(nums) << endl;
    cout << slowFastApproach(nums) << endl;
    return 0;
}