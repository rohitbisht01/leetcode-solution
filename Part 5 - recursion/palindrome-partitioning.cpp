#include <bits/stdc++.h>
using namespace std;

// T(N) =>
// S(N) =>

bool isPalindrome(string s, int left, int right)
{
    while (left <= right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void solve(int ind, string s, vector<string> &temp, vector<vector<string>> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            temp.push_back(s.substr(ind, i - ind + 1));
            solve(i + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;

    solve(0, s, temp, ans);
    return ans;
}

int main()
{
    string s = "aabb";
    vector<vector<string>> ans = partition(s);

    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}