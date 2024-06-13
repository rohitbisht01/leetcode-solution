#include <bits/stdc++.h>
using namespace std;

// rotate the matrix 90 degrees clockwise.

// transpose the matrix
// reverse the rows

// T(N) => O(N * N) + O(N * N) => one for transposing the matrix and other for reversing the matrix
// S(N) => O(1)

void rotateMatrix(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    rotateMatrix(mat);

    for (auto it : mat)
    {
        for (auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}