#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-10

class Solution {
public:
    int bruteforce(vector<int>& nums) {
        const int N = 10e5;
        const int n = nums.size();
        int freq[N]{0};
        int ret = INT_MIN;
        for (int l = 0; l < n; l++) {
            int tb[2] = {0}; // even, odd
            for (int r = l; r < n; r++) {
                if (++freq[nums[r]] == 1)
                    tb[nums[r] & 1] += 1;
                if (tb[0] == tb[1]) {
                    ret = max(ret, r - l + 1);
                }
            }
            // reset freq
            for (int i = l; i < n; i++) {
                freq[nums[i]] = 0;
            }
        }
        return ret == INT_MIN ? 0 : ret;
    }
    int longestBalanced(vector<int>& nums) {
        return bruteforce(nums);
    }
};