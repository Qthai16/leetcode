#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        for (int i = k - 1; i < nums.size(); i++) {
            auto diff = nums[i] - nums[i - k + 1];
            mindiff = min(mindiff, diff);
        }
        return mindiff;
    }
};