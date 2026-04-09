#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        using Ele = pair<int, int>; // height, index
        stack<Ele, vector<Ele>> s;
        int ret = INT_MIN;
        const auto& h = heights;
    }
};