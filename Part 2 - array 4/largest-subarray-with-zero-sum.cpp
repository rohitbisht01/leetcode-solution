#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(N * N)
// S(N) => O(1)

// consider all possible subarrays of the given array and check for the subarrays that sum to zero. Among these valid subarrays (a sum equal to zero) we’ll return the length of the largest subarray by maintaining a variable, say max.
int maxLen(vector<int> &A, int n)
{
    // Your code here
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            if (sum == 0)
            {
                maxlen = max(maxlen, j - i + 1);
            }
        }
    }
    return maxlen;
}

// better approach
// T(N) => O(N)
// S(N) => O(N)
int maxLen(vector<int> &A, int n)
{
    // Your code here
    int maxi = 0;
    int sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (map.find(sum) != map.end())
            {
                maxi = max(maxi, i - map[sum]);
            }
            else
            {
                map[sum] = i;
            }
        }
    }
    return maxi;
}