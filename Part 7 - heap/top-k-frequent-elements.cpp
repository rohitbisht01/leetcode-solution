#include <bits/stdc++.h>
using namespace std;

// brute force
// use hashmap to store the frequency of each number and then push all of them into a pair of vectors and then sort it in asc or desc order and then return the k top frequent numbers

// T(N) => O(N) + O(N log N) + O(K) => O(n log n)
// S(N) => O(N) for map and vector of pairs + O(N) for resultant vector => O(N)
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) // O(N)
    {
        map[nums[i]]++;
    }

    vector<pair<int, int>> pair;
    for (auto it : map)
    {
        pair.push_back({it.second, it.first});
    }

    vector<int> ans;
    sort(pair.rbegin(), pair.rend());               // O(N log N)
    for (int i = 0; i < pair.size() && k != 0; i++) // O(K)
    {
        ans.push_back(pair[i].second);
        k--;
    }

    return ans;
}

// using priority queue
// so use hashmap to store the frequency of elements and then use priority queue of pairs to store all the elements from map and the pop it until k elements are popped
// T(N) => O(N log K)
// S(N) => O(N)
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    vector<int> ans;

    priority_queue<pair<int, int>> pq;
    for (auto it : map)
    {
        pq.push({it.second, it.first});
    }

    while (k != 0)
    {
        auto it = pq.top();
        pq.pop();
        ans.push_back(it.second);
        k--;
    }

    return ans;
}

int main()
{
    return 0;
}