#include <bits/stdc++.h>
using namespace std;

// T(N) => O(2^N)
// S(N) => O(2^N)

void solve(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp)
{
    if (ind == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    solve(ind + 1, nums, ans, temp);
    temp.push_back(nums[ind]);
    solve(ind + 1, nums, ans, temp);
    temp.pop_back();
}

vector<vector<int>> generateAllSubets(vector<int> &nums)
{
    vector<vector<int>> ans;
    int ind = 0;
    vector<int> temp;
    solve(ind, nums, ans, temp);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = generateAllSubets(nums);

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