#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxSum = INT_MIN;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            auto sum = static_cast<int64_t>(nums[i++]) + static_cast<int64_t>(nums[j--]);
            maxSum = max(static_cast<int>(sum), maxSum);
        }
        return maxSum;
    }
};
