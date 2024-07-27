#include <bits/stdc++.h>
using namespace std;

// brute force
// lineary traverse the array and store all the elements in an arry and sort it and return the median based on the len of arr
// odd len => return middle element
// even length => return (mid + (mid+1))/2

// T(N) => O(MXN) + O(MXN(log(MXN)))
// S(N) => O(MXN)

int median(vector<vector<int>> &matrix, int R, int C)
{
    vector<int> ans;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ans.push_back(matrix[i][j]);
        }
    }

    sort(ans.begin(), ans.end());

    int len = ans.size();
    if (len % 2)
    {
        return ans[len / 2];
    }
    else
    {
        return (ans[len / 2] + ans[(len / 2) + 1]) / 2;
    }
}

int main()
{
    return 0;
}