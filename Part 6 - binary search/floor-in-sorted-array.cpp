#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(N)
// S(N) => O(1)
int findFloor(vector<int> v, int x)
{
    int ele = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= x)
            ele = i;
        else
            break;
    }
    return ele;
}

// binary search
// T(N) => O(log N)
// S(N) => O(1)
int findFloor(vector<int> v, int x)
{
    int n = v.size();
    int ele = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] <= x)
        {
            ele = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ele;
}

int main()

{
    vector<int> v = {1, 2, 8, 10, 11, 12, 19};
    int x = 5;
    cout << findFloor(v, x);
    return 0;
}