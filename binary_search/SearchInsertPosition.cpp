#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            auto mid = l + (r - l)/2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums, target);
    }
};