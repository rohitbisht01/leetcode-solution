#include <bits/stdc++.h>
using namespace std;

// approach => maintain two varibles maxones and ones, ones for storing the count of ones in consecutive sequence and maxones for storing the maxlen we have encountered so far
// T(N) => O(N)
// S(N) => O(1)

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxones = 0, ones = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            ones++;
        }
        else
        {
            ones = 0;
        }
        maxones = max(maxones, ones);
    }
    return maxones;
}