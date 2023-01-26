// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ans;
    vector<vector<int>> v;
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        merger(intervals, intervals[0][0], intervals[0][1], 0, 1);
        return v;
    }

public:
    void merger(vector<vector<int>> &intervals, int start, int end, int i, int j)
    {
        if (j == intervals.size() and v.size() == 0)
        {
            ans.push_back(start);
            ans.push_back(end);
            v.push_back(ans);
        }
        if (j >= intervals.size())
        {
            return;
        }
        if (end >= intervals[j][0])
        {
            start = min(start, intervals[j][0]);
            end = max(end, intervals[j][1]);
            if (j + 1 == intervals.size())
            {
                ans.push_back(start);
                ans.push_back(end);
                v.push_back(ans);
            }
        }
        if (end < intervals[j][0])
        {
            ans.push_back(start);
            ans.push_back(end);
            v.push_back(ans);
            ans.clear();
            start = intervals[j][0];
            end = intervals[j][1];
            if (j + 1 == intervals.size())
            {
                ans.push_back(start);
                ans.push_back(end);
                v.push_back(ans);
            }
        }
        merger(intervals, start, end, j, j + 1);
    }
};