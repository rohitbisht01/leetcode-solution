#include <bits/stdc++.h>
using namespace std;

// brute force => iterate over the arr and check i*i <= n
int floorSqrt(int n)
{
    int ans = 0;
    // linear search on the answer space:
    for (long long i = 1; i <= n; i++)
    {
        long long val = i * i;
        if (val <= n * 1ll)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

// brute force => use built in method : sqrt(number)
long long int floorSqrt(long long int x)
{
    long long int ans = sqrt(x);
    return floor(ans);
}

// using binary search
// T(N) => O(log n)
// S(N) => O(1)
int floorSqrt(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = mid * mid;
        if (val <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    return 0;
}