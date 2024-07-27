#include <bits/stdc++.h>
using namespace std;

// brute force

// use set to store the unique subsets
// T(N) => O(2 ^N ∗ N)
// S(N) => O(2 ^N ∗ N)

void solve(int ind, vector<int> &nums, set<vector<int>> &set, vector<int> &temp)
{
    if (ind == nums.size())
    {
        set.insert(temp);
        return;
    }

    solve(ind + 1, nums, set, temp);
    temp.push_back(nums[ind]);
    solve(ind + 1, nums, set, temp);
    temp.pop_back();
}

// optimized approach

// T(N) => O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n)
// S(N) => O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.

void solve(int ind, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
{
    ans.push_back(temp);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    set<vector<int>> set;
    int ind = 0;
    vector<int> temp;
    solve(ind, nums, set, temp);

    for (vector<int> ls : set)
    {
        ans.push_back(ls);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);

    for (vector<int> temp : ans)
    {
        for (int num : temp)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
