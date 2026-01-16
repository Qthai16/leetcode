#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            auto mid = l + (r - l)/2;
            int left = mid - 1 >= 0 ? nums[mid - 1] : INT_MIN;
            int right = mid + 1 < nums.size() ? nums[mid + 1] : INT_MIN;
            auto val = nums[mid];
            if (left < val && val > right)
                return mid;
            if (left < val) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
