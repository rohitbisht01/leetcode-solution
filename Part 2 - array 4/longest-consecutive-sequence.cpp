#include <bits/stdc++.h>
using namespace std;

// T(N) => O(N log N) + O(N)
// S(N) => O(1)

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int maxcnt = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            if (nums[i - 1] + 1 == nums[i])
            {
                cnt++;
            }
            else
            {
                maxcnt = max(maxcnt, cnt);
                cnt = 1;
            }
        }
    }
    return max(maxcnt, cnt);
}

// using set
/*
Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).

Space Complexity: O(N), as we are using the set data structure to solve this problem.

Note: The time complexity is computed under the assumption that we are using unordered_set and it is taking O(1) for the set operations.

If we consider the worst case the set operations will take O(N) in that case and the total time complexity will be approximately O(N2).
And if we use the set instead of unordered_set, the time complexity for the set operations will be O(logN) and the total time complexity will be O(NlogN).
*/
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> set;
    for (int num : nums)
        set.insert(num);

    for (auto it : set)
    {
        if (set.find(it - 1) == set.end())
        {
            // find consecutive numbers
            int cnt = 1;
            int num = it;
            while (set.find(num + 1) != set.end())
            {
                num = num + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}