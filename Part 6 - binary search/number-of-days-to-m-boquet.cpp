#include <bits/stdc++.h>
using namespace std;

// brute force
bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    int n = bloomDay.size();
    int cnt = 0;
    int numOfBoquets = 0;
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= day)
        {
            cnt++;
        }
        else
        {
            numOfBoquets += (cnt / k);
            cnt = 0;
        }
    }

    numOfBoquets += (cnt / k);
    return numOfBoquets >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size();

    if (val > n)
        return -1;

    // find min and max
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    for (int i = mini; i <= maxi; i++)
    {
        if (possible(bloomDay, i, m, k))
        {
            return i;
        }
    }
    return -1;
}

// using binary search
bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    int n = bloomDay.size();
    int cnt = 0;
    int numOfBoquets = 0;
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= day)
        {
            cnt++;
        }
        else
        {
            numOfBoquets += (cnt / k);
            cnt = 0;
        }
    }

    numOfBoquets += (cnt / k);
    return numOfBoquets >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size();

    if (val > n)
        return -1;

    // find min and max
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(bloomDay, mid, m, k))
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