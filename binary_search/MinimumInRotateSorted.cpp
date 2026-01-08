#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return min(nums[0], nums[1]);
        int l = 0, r = nums.size();
        while (l < r) {
            auto mid = l + (r - l)/2;
            if ((mid > 0 && nums[mid] < nums[mid - 1]) && (mid + 1 < nums.size() && nums[mid] < nums[mid + 1]))
                return nums[mid];
            if (nums[mid] > nums[r - 1]) { // go right
                l = mid + 1;
            } else { // go left
                r = mid;
            }
        }
        return l + 1 < nums.size() ? min(nums[l], nums[l + 1]) : nums[l];
    }
};