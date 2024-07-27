#include <bits/stdc++.h>
using namespace std;

void solve(int ind, string str, vector<string> &ans)
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

vector<string> permute(string &str)
{
    vector<string> ans;

    solve(0, str, ans);
    return ans;
}

int main()
{
    string str = "abacb";
    vector<string> ans = permute(str);

    return 0;
}