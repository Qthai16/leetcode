#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int oldSolution(int target, vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) {
            return nums[0] >= target ? 1 : 0;
        }
        int l = 0, r = 0;
        int curSum = 0, ans = INT_MAX;
        int lastr = -1;
        while (r < nums.size()) {
            if (lastr != r) {
                lastr = r;
                curSum += nums[r];
            }
            if (curSum >= target) {
                ans = min(ans, r - l + 1);
                curSum -= nums[l];
                l++;
            } else
                r++;
        }
        r -= 1;// backtrack r to nums.size() - 1
        while (l <= r) {
            if (curSum >= target) {
                ans = min(ans, r - l + 1);
            } else
                break;
            curSum -= nums[l];
            l++;
        }
        return ans == INT_MAX ? 0 : ans;
    }

    int newSolution(int target, vector<int> &nums) {
        // prefix sum + sliding windows
        if (nums.empty())
            return 0;
        vector<int> presum(nums.size() + 1, 0);
        for (auto i = 0; i < nums.size(); i++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        int minlen = INT_MAX;
        int l = 0, r = l + 1;
        int cursum = 0;
        while (r < presum.size()) {
            cursum = presum[r] - presum[l];
            if (cursum < target) {
                r++;
                continue;
            }
            // todo: this could be optimize instead of iterate l one by one
            while (cursum >= target && l < r) { // shrink the windows until it's invalid
                minlen = min(minlen, r - l);
                l++;
                cursum = presum[r] - presum[l];
            }
            r = l + 1;
        }
        auto finalsum = presum[r - 1] - presum[l];
        if (finalsum >= target) {
            minlen = min(r - l, minlen);
        }
        return minlen == INT_MAX ? 0 : minlen;
    }

    int minSubArrayLen(int target, vector<int> &nums) {
        return newSolution(target, nums);
    }
};
