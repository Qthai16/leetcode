#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cursum = nums[0], maxsum = cursum;
        for (auto i = 1; i < nums.size(); i++) {
            cursum += nums[i];
            if (cursum < nums[i])
                cursum = nums[i]; // start again at nums[i]
            maxsum = max(maxsum, cursum);
        }
        return maxsum;
    }
};
