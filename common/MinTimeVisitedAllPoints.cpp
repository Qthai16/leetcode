#include <bits/stdc++.h>
using namespace std;

#include "../debug/StrUtils.h"

// https://leetcode.com/problems/minimum-time-visiting-all-points/description

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int ret = 0;
        for (auto i = 0; i < points.size() - 1; i++) {
            if (points[i][0] == points[i + 1][0]) {// same x
                // travel vertically
                ret += abs(points[i][1] - points[i + 1][1]);
            } else if (points[i][1] == points[i + 1][1]) {// same y
                // travel horizontally
                ret += abs(points[i][0] - points[i + 1][0]);
            } else {
                auto x1 = points[i][0], y1 = points[i][1];
                auto x2 = points[i + 1][0], y2 = points[i + 1][1];
                if (x2 > x1 && y2 > y1) { // top right
                    auto xy = abs(x2 - x1) + abs(y2 - (y1 + x2 - x1));
                    auto yx = abs(y2 - y1) + abs(x2 - (x1 + y2 - y1));
                    ret += min(xy, yx);
                } else if (x2 > x1 && y2 < y1) { // bottom right
                    auto xy = abs(x2 - x1) + abs(y1 - (y2 + x2 - x1));
                    auto yx = abs(y1 - y2) + abs(x2 - (x1 + y1 - y2));
                    ret += min(xy, yx);
                } else if (x2 < x1 && y2 > y1) { // top left
                    auto xy = abs(x1 - x2) + abs(y2 - (y1 + x1 - x2));
                    auto yx = abs(y2 - y1) + abs(x1 - (x2 + y2 - y1));
                    ret += min(xy, yx);
                } else if (x2 < x1 && y2 < y1) { // bottom left
                    auto xy = abs(x1 - x2) + abs(y1 - (y2 + x1 - x2));
                    auto yx = abs(y1 - y2) + abs(x1 - (x2 + y1 - y2));
                    ret += min(xy, yx);
                }
            }
        }
        return ret;
    }
};