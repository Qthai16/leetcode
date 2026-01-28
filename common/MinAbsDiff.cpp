#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if (arr.size() <= 1) return {};
        int minDiff = INT_MAX;
        vector<vector<int>> ret;
        for (int i = 1; i < arr.size(); i++) {
            auto diff = abs(arr[i] - arr[i - 1]);
            if (diff < minDiff) {
                minDiff = diff;
                ret.clear();
                ret.push_back({arr[i - 1], arr[i]});
            } else if (diff == minDiff) {
                ret.push_back({arr[i - 1], arr[i]});
            }
        }
        return ret;
    }
};