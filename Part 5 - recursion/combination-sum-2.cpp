#include <bits/stdc++.h>
using namespace std;

// T(N) => O(2^N * K)
// S(N) => O(2^N * K)

void solve(int ind, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans, int target)
{

    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = ind; i < candidates.size(); i++)
    {
        if (i > ind && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;

        temp.push_back(candidates[i]);
        solve(i + 1, candidates, temp, ans, target - candidates[i]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    int ind = 0;
    solve(ind, candidates, temp, ans, target);
    return ans;
}