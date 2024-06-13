#include <bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum in an Array

// approach 1: generating all the subsets and then checking the sum and considering the maximum among them
// approach 2: to get the sum of current subarray we just need to add current element to the subarray sum
// approach 3: maintain two pointer one storing the cursum so far and another storing maximum sum we have achieved so far and if the cursum becomes less than 0 then update the cursum to 0

// Follow up: print the subarray having maximum sum

// T(N) => O(N * N * N)
// S(N) => O(1)
int bruteForce(vector<int> &nums)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }

            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// T(N) => O(N * N)
// S(N) => O(1)
int kadane(vector<int> &nums)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
        }

        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// T(N) => O(N)
// S(N) => O(1)
int optimized(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int curSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curSum += nums[i];
        maxSum = max(maxSum, curSum);
        if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}

void printMaximumSubarray(vector<int> &nums)
{
    int start = 0, ansStart = 0, ansEnd = 0;
    int maxsum = INT_MIN, cursum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cursum == 0)
            start = i;

        cursum += nums[i];
        if (cursum > maxsum)
        {
            maxsum = max(cursum, maxsum);
            ansStart = start;
            ansEnd = i;
        }
        if (cursum < 0)
            cursum = 0;
    }

    for (int i = ansStart; i <= ansEnd; i++)
        cout << nums[i] << " ";

    cout << endl;
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    cout << bruteForce(nums) << endl;
    cout << kadane(nums) << endl;
    cout << optimized(nums) << endl;
    printMaximumSubarray(nums);
    return 0;
}