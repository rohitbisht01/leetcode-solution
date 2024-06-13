#include <bits/stdc++.h>
using namespace std;

// brute force
// Time Complexity: O(N*logN) + O(N), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
// Space Complexity: O(N) as we are using a map data structure.

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> map;
    for (int num : nums)
    {
        map[num]++;
    }

    for (auto it : map)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;
}

// optimized approach
// T(N) => O(N)
// S(N) => O(1)
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }

        if (candidate == num)
            count++;
        else
            count--;
    }

    return candidate;
}

// Brute force
// Time Complexity: O(N*logN), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN).
// If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
// Space Complexity: O(N) as we are using a map data structure. We are also using a list that stores a maximum of 2 elements. That space used is so small that it can be considered constant.
vector<int> majorityElementThree(vector<int> &nums)
{
    vector<int> ans;
    unordered_map<int, int> map;
    for (int num : nums)
    {
        map[num]++;
    }

    for (auto it : map)
    {
        if (it.second > (nums.size() / 3))
            ans.push_back(it.first);
    }
    return ans;
}

// better approach would be extended moore algorithm

int main()
{
}