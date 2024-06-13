#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(N * N)
// S(N) => O(1)
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

// better approach
// hashing
// T(N) => O(N)
// S(N) => O(1)
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int moreNeeded = target - num;
        if (map.find(moreNeeded) != map.end())
        {
            return {map[moreNeeded], i};
        }

        map[num] = i;
    }
    return {-1, -1};
}