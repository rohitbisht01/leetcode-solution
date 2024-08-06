#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // efficient approach
    // T(N) => O(N log N) => Because heap operations like insert and extract take O(Logn) time in priority_queue and for all n elements it takes n*logn.
    // S(N) => O(N)

    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for (long long int i = 0; i < n; i++)
            pq.push(arr[i]);

        long long int cost = 0;
        while (pq.size() > 1)
        {
            long long int num = pq.top();
            // cout<<"num"<<num<<endl;
            pq.pop();
            num += pq.top();
            // cout<<"Second num+previous"<<num<<endl;
            cost += num;
            // cout<<"cost"<<cost<<endl;
            pq.pop();
            pq.push(num);
        }

        return cost;
    }
};

int main()
{
    return 0;
}