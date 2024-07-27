#include <bits/stdc++.h>
using namespace std;

// T(N) => O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
// S(N) =>  O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

void solve(vector<int> arr, int ind, int sum, vector<int> &ans)
{
    if (ind == arr.size())
    {
        ans.push_back(sum);
        return;
    }

    solve(arr, ind + 1, sum, ans);

    solve(arr, ind + 1, sum + arr[ind], ans);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    int ind = 0;
    int sum = 0;
    vector<int> ans;
    solve(arr, ind, sum, ans);
    return ans;
}

int main()
{
    vector<int> arr = {5, 2, 1};
    vector<int> ans = subsetSums(arr, arr.size());

    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}