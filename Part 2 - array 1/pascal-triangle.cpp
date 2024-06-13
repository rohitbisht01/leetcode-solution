#include <bits/stdc++.h>
using namespace std;

// approach 1: T(N) => O(N * N)
// S(N) => O(N * N)

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> tri;
    vector<int> res;
    res.push_back(1);
    tri.push_back(res);

    for (int i = 1; i < n; i++)
    {
        vector<int> prev = tri[i - 1];
        vector<int> temp;
        temp.push_back(1);
        for (int j = 1; j < prev.size(); j++)
        {
            temp.push_back(prev[j - 1] + prev[j]);
        }
        temp.push_back(1);
        tri.push_back(temp);
    }

    return tri;
}

int main()
{
    int n = 5;
    vector<vector<int>> res = pascalTriangle(n);
    for (vector<int> ls : res)
    {
        for (int num : ls)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
