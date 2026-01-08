#include <bits/stdc++.h>

// https://leetcode.com/problems/insert-interval/

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return vector<vector<int>>{newInterval};
        auto it = std::lower_bound(intervals.begin(), intervals.end(), newInterval, [](const vector<int>& l, const vector<int>& r) -> bool {
            return l[0] < r[0];
        });
        // insert
        it = intervals.insert(it, newInterval);
        auto ind = it - intervals.begin();
        // merge
        auto prev = ind != 0 ? ind - 1 : ind;
        auto cur = ind != 0 ? ind : ind + 1;
        vector<vector<int>> ret;
        for (auto i = 0; i < prev; i++) {
            ret.push_back(intervals[i]);
        }
        while (cur < intervals.size() && intervals[prev][1] >= intervals[cur][0]) {
            intervals[prev][1] = max(intervals[prev][1], intervals[cur][1]);
            cur += 1;
        }
        ret.push_back(intervals[prev]);
        while (cur < intervals.size()) {
            if (intervals[cur][0] <= ret[ret.size() - 1][1]) {
                ret[ret.size() - 1][1] = max(ret[ret.size() - 1][1], intervals[cur][1]);
                cur++;
                continue;
            }
            ret.push_back(intervals[cur]);
            cur++;
        }
        return ret;
    }
};