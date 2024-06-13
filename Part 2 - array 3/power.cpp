#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(N)
// S(N) => O(1)
double myPow(double x, int n)
{
    double ans = 1.0;

    for (int i = 0; i < abs(n); i++)
    {
        ans = ans * x;
    }

    if (n < 0)
    {
        return 1.0 / ans;
    }
    return ans;
}

// using binary exponentiation
// Approach: Initialize ans as 1.0  and store a duplicate copy of n i.e nn using to avoid overflow

// Check if nn is a negative number, in that case, make it a positive number.

//   Keep on iterating until nn is greater than zero,
//   now if nn is an odd power then multiply x with ans ans reduce nn by 1. Else multiply x with itself and divide nn by two.

//   Now after the entire binary exponentiation is complete and nn becomes zero,
//   check if n is a negative value we know the answer will be 1 by and.

// T(N) => O(log n)
// S(N) => O(1)

double myPow(double x, int n)
{
    double ans = 1.0;
    int nn = n;
    if (nn < 0)
        nn = -1 * nn;

    while (nn)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn--;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
        ans = 1.0 / ans;
    return ans;
}

int main() {}