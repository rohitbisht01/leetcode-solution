#include <bits/stdc++.h>
using namespace std;

// T(N) => O(2^N * K)
// S(N) => O(2^N * K)

void solve(int ind, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans, int target)
{
    if (ind == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }

    if (candidates[ind] <= target)
    {
        temp.push_back(candidates[ind]);
        solve(ind, candidates, temp, ans, target - candidates[ind]);
        temp.pop_back();
    }
    solve(ind + 1, candidates, temp, ans, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;

    int ind = 0;
    vector<int> temp;
    solve(ind, candidates, temp, ans, target);

    return ans;
}