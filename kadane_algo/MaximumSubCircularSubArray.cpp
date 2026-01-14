#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-sum-circular-subarray/description/
// solution copy from https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/178422/one-pass-by-lee215-navi/?envType=study-plan-v2&envId=top-interview-150
// todo: try check other solutions from discuss section

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int curmax = 0, curmin = 0, maxsum = nums[0], minsum = nums[0], totalsum = 0;
        for (const auto& n : nums) {
            curmax = max(curmax + n, n);
            maxsum = max(curmax, maxsum);
            curmin = min(curmin + n, n);
            minsum = min(curmin, minsum);
            totalsum += n;
        }
        return maxsum > 0 ? max(maxsum, totalsum - minsum) : maxsum;
    }
};
