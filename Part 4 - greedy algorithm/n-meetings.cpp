#include <bits/stdc++.h>
using namespace std;

// T(N) => O(N) + O(N log N) + O(N) => O( N log N )
// S(N) => O(N)

struct meeting
{
    int start;
    int end;
    int pos;
};

class Solution
{
public:
    bool static comparator(struct meeting m1, struct meeting m2)
    {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for (int i = 0; i < n; i++)
        {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        sort(meet, meet + n, comparator);

        vector<int> ans;
        int limit = meet[0].end;
        ans.push_back(meet[0].pos);

        for (int i = 1; i < n; i++)
        {
            if (meet[i].start > limit)
            {
                limit = meet[i].end;
                ans.push_back(meet[i].pos);
            }
        }
        return ans.size();
    }
};