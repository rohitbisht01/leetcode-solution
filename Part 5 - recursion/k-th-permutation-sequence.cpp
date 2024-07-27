#include <bits/stdc++.h>
using namespace std;

void solve(int ind, string &str, vector<string> &ans)
{
    if (ind == str.size())
    {
        ans.push_back(str);
        return;
    }

    for (int i = ind; i < str.size(); i++)
    {
        swap(str[i], str[ind]);
        solve(ind + 1, str, ans);
        swap(str[i], str[ind]);
    }
}
string getPermutation(int n, int k)
{
    string str = "";
    for (int i = 1; i <= n; i++)
        str.push_back('0' + i);
    vector<string> ans;
    solve(0, str, ans);

    return ans[k - 1];
}

int main()
{
    int n = 4;
    int k = 3;
    string ans = getPermutation(n, k);
    cout << ans << endl;
    return 0;
}