#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() <= 1) return points.size();
        std::sort(points.begin(), points.end(), [](const vector<int> &l, const vector<int> &r) -> bool {
            return l[0] < r[0];
        });
        stack<pair<int, int>> s;
        int ret = 0;
        for (auto i = 1; i < points.size();) {
            if (!s.empty()) {
                auto pair = s.top();
                if (pair.second >= points[i][0]) {
                    s.pop();
                    s.push({points[i][0], min(pair.second, points[i][1])});
                } else {
                    ret += 1;
                    s.pop();
                    s.push({points[i][0], points[i][1]});
                }
            } else {
                if (points[i - 1][1] < points[i][0]) {
                    ret += 1;
                    s.push({points[i][0], points[i][1]});
                } else {
                    s.push({points[i][0], min(points[i - 1][1], points[i][1])});
                }
            }
            i++;
        }
        while (!s.empty()) {
            ret += 1;
            s.pop();
        }
        return ret;
    }
};
