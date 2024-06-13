#include <bits/stdc++.h>
using namespace std;

// approach 1: first loop for buying the stock and then second loop for selling the stock and if the profit is greater than update maxProfit

// T(N) => O( N * N )
// S(N) => O(1)

int buySellStock(vector<int> &nums)
{
    int n = nums.size();
    int maxProfit = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int profit = nums[j] - nums[i];
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}

// approach 2: maintain the minimum from the start and compare it with every element of an array and if it is greater than minimum, take the diff.
// and update the maxProfit

// T(N) => O(N)
// S(N) => O(1)

int buyAndSellStock(vector<int> &nums)
{
    int n = nums.size();
    int maxProfit = INT_MIN;
    int smallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        smallest = min(smallest, nums[i]);
        maxProfit = max(maxProfit, nums[i] - smallest);
    }

    return maxProfit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << buySellStock(nums) << endl;
    cout << buyAndSellStock(nums) << endl;

    return 0;
}