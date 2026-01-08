#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
    bool binary_search(const vector<int>& nums, int low, int high, int target) {
        int l = low, r = high;
        while (l < r) {
            auto mid = l + (r - l)/2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return (l < high && nums[l] == target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // naive approach, search row by row, O(n*logN)
        for (const auto& nums : matrix) {
            if (binary_search(nums, 0, nums.size(), target)) return true;
        }
        return false;
        // O(N) approach, traverse right to left until value < target, then go down
        int i = 0; // row index
        int j = matrix[0].size() - 1; // col index
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) { // move left
                j -= 1;
            } else { // move down
                i += 1;
            }
        }
        return i < matrix.size() && j >= 0;
    }
};