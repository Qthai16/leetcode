#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        int prev = 0; // index of the previous interval to compare with
        int ret = 0;
        // vector<vector<int>> non_overlapped;
        // non_overlapped.push_back(intervals[0]);
        for (auto i = 1; i < intervals.size(); i++) {
            auto start = intervals[i][0];
            if (start >= intervals[prev][1]) { // non-overlapped
                prev = i;
                // non_overlapped.push_back(intervals[i]);
                continue;
            }
            ret += 1;
        }
        return ret;
    }
};