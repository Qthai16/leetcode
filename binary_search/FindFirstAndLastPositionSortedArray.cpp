#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int target, int start, int end) {
        auto l = start, r = end;
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
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums, target, 0, nums.size());
        if (l >= nums.size() || nums[l] != target)
            return {-1, -1};
        auto r = lower_bound(nums, target + 1, l, nums.size());
        if (r - 1 >= 0 && nums[r - 1] == target) {
            return {l, r - 1};
        }
        return {l, l};
    }
};