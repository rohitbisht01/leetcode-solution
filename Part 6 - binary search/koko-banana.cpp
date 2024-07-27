#include <bits/stdc++.h>
using namespace std;

// brute force

// at max koko can eat all the bananas in maxi hours but we want the minimum hour which is less than or equal to h
// brute force is to statrt with 1 banana per hr and check if result is less than or equal to h

// T(N) => O(N * N)
// S(N) => O(1)
int findMax(vector<int> &bananas)
{
    int maxi = INT_MIN;
    for (int num : bananas)
    {
        maxi = max(maxi, num);
    }

    return maxi;
}

int calculateTotalHrs(vector<int> &bananas, int hourly)
{
    int totalhrs = 0;
    for (int i = 0; i < bananas.size(); i++)
    {
        totalhrs += ceil((double(bananas[i]) / (double(hourly))));
    }

    return totalhrs;
}

int kokoBananas(vector<int> &bananas, int h)
{
    int maxi = findMax(bananas);

    for (int i = 1; i <= maxi; i++)
    {
        int reqTime = calculateTotalHrs(bananas, i);
        if (reqTime <= h)
        {
            return i;
        }
    }

    return maxi;
}

// efficient approach
// use binary search from 1 to max and check if the totalHrs <= h and update low and high, at last return low

// T(N) => O(N) + O(log (max(arr))) => O(M log N)
// S(N) => O(1)

int findMax(vector<int> &piles)
{
    int maxi = INT_MIN;
    for (int num : piles)
        maxi = max(maxi, num);
    return maxi;
}

int eatingTime(vector<int> &piles, int hourly)
{
    int ans = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        ans += ceil(double(piles[i]) / double(hourly));
    }
    return ans;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int maxi = findMax(piles);

    int low = 1, high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int totalHrs = eatingTime(piles, mid);
        if (totalHrs <= h)
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
    vector<int> bananas = {7, 15, 6, 3};
    int h = 8;
    cout << kokoBananas(bananas, h) << endl;
    cout << minEatingSpeed(bananas, h) << endl;
    return 0;
}