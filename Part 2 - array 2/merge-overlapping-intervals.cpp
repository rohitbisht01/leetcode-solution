#include <bits/stdc++.h>
using namespace std;

//

// T(N) => O(N * log N) + O(N)
// S(N) => O(N)

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &mat)
{
    vector<vector<int>> result;
    int n = mat.size();

    sort(mat.begin(), mat.end());
    for (int i = 0; i < n; i++)
    {
        if (result.empty() || mat[i][0] > result.back()[1])
        {
            result.push_back(mat[i]);
        }
        else
        {
            result.back()[1] = max(result.back()[1], mat[i][1]);
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = mergeOverlappingIntervals(mat);

    for (auto it : result)
    {
        for (int num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}