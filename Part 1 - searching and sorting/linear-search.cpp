#include <bits/stdc++.h>
using namespace std;

// T(N) => O(N)
// S(N) => O(1)

bool linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n = 7;
    int arr[n] = {2, 3, 4, 1, 2, 4, 7};
    int target = -3;
    bool isPresent = linearSearch(arr, n, target);
    if (isPresent)
        cout << "Target element is present" << endl;
    else
        cout << "Target element is not present" << endl;
    return 0;
}