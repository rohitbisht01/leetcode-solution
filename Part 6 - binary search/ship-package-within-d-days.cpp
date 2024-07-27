#include <bits/stdc++.h>
using namespace std;

// brute force approach
// minCapacity will be the max weight in the array and maxCapacity will be the summation of all the weights in the array
// and the minimum total weight should lie in range of minCapacity and maxCapacity

// T(N) => O(N * N)
// S(N) => O(1)

int solve(vector<int> &weights, int maxLoad)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > maxLoad)
        {
            days++;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int n = weights.size();

    for (int i = maxi; i <= sum; i++)
    {
        if (solve(weights, i) <= days)
        {
            return i;
        }
    }
    return -1;
}

// binary search
// T(N) => O(N * log(sum(weights[]) - max(weights[]) + 1)),
// S(N) => O(1)

int solve(vector<int> &weights, int maxLoad)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > maxLoad)
        {
            days++;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int n = weights.size();

    int low = maxi, high = sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int d = solve(weights, mid);
        if (d <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    return 0;
}