#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O( M * N )
// S(N) => O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// using binary search
// T(N) => O(log(NxM))
// S(N) => O(1)

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = 0, high = rows * cols - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int ele = matrix[mid / cols][mid % cols];
        if (target == ele)
            return true;

        if (target < ele)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;
    cout << searchMatrix(matrix, target);
}