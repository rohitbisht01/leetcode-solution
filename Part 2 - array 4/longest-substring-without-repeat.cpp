#include <bits/stdc++.h>
using namespace std;

// T(N) => O(N)
// S(N) => O(N)
int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;
    int cnt = 1;
    int left = 0, right = 0;
    set<char> set;
    while (right < s.length())
    {
        if (set.find(s[right]) != set.end())
        {
            set.erase(s[left]);
            left++;
        }
        else
        {
            set.insert(s[right]);
            right++;
            int sz = set.size();
            cnt = max(cnt, sz);
        }
    }
    return cnt;
}