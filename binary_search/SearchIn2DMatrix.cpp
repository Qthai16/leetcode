#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    int lower_bound(vector<int>& v, int target) {
        int l = 0, r = v.size();
        while (l < r) {
            auto m = l + (r - l)/2;
            if (v[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // naive appoach, search line by line
        for (auto i = 0; i < matrix.size(); i++) {
            auto j = lower_bound(matrix[i], target);
            if (j < matrix[i].size() && matrix[i][j] == target)
                return true;
        }
        return false;
    }
};