#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(M)
// S(N) => O(1)

//  func(x, n) returns the value of x raised to the power n i.e. xn.
// Power exponential method:
long long func(int b, int exp)
{
    int base = b;
    long long ans = 1;

    while (exp > 0)
    {
        if (exp % 2)
        {
            exp--;
            ans = ans * base;
        }
        else
        {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}

int NthRoot(int n, int m)
{
    for (int i = 0; i <= m; i++)
    {
        long long value = func(i, n);
        if (value == m * 1ll)
            return i;
        else if (value > m * 1ll)
            break;
    }
    return -1;
}

// using binary search
// T(N) => O(log n)
// S(N) => O(1)

// return 1, if == m:
// return 0, if < m:
// return 2, if > m:
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;

    return 0;
}
int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
            return mid;

        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";

    return 0;
}