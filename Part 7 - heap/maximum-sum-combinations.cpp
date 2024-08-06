#include <bits/stdc++.h>
using namespace std;

// brute force
// T(N) => O(N*N), As we are running a nested for loop of size N*N and sorting the array whose complexity is O(NlogN), So total complexity is O(N*N).
// S(N) => O(N * N)
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans.push_back(A[i] + B[j]);
        }
    }
    sort(ans.rbegin(), ans.rend());
    vector<int> temp;
    for (int i = 0; i < ans.size() && K != 0; i++)
    {
        temp.push_back(ans[i]);
        K--;
    }

    return temp;
}

// priority queue
// T(N) => O()
// S(N) => O(N * N)
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
{
    priority_queue<int> maxHeap;
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            maxHeap.push(A[i] + B[j]);
        }
    }

    while (K != 0)
    {
        ans.push_back(maxHeap.top());
        maxHeap.pop();
        K--;
    }

    return ans;
}

int main()
{
    return 0;
}