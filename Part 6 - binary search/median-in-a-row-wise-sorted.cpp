#include <bits/stdc++.h>
using namespace std;

// brute force
// store all the elements into an array and sort it after sorting calculate the median
// check if n is even or odd
// T(N) => O(M * N log(N * M))
// S(N) => O(M * N)

int median(vector<vector<int>> &matrix, int R, int C)
{
    // code here
    vector<int> ans;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ans.push_back(matrix[i][j]);
        }
    }
    sort(ans.begin(), ans.end());

    int n = R * C;
    if (n % 2 == 0)
    {
        return (ans[n] + ans[n - 1]) / 2;
    }
    return ans[n / 2];
}

int main()
{
    return 0;
}