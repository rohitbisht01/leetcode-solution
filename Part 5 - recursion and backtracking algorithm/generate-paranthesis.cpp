#include <bits/stdc++.h>
using namespace std;

void solve(int openCnt, int closeCnt, string str, vector<string> &ans)
{
    if (openCnt == 0 && closeCnt == 0)
    {
        ans.push_back(str);
        return;
    }

    if (openCnt > 0)
    {
        str.push_back('(');
        solve(openCnt - 1, closeCnt, str, ans);
        str.pop_back();
    }

    if (closeCnt > 0)
    {
        if (openCnt < closeCnt)
        {
            str.push_back(')');
            solve(openCnt, closeCnt - 1, str, ans);
            str.pop_back();
        }
    }
}
vector<string> generateParenthesis(int n)
{
    string str = "";
    vector<string> ans;
    solve(n, n, str, ans);
    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(3);
    for (string it : ans)
    {
        cout << it << endl;
    }
    return 0;
}