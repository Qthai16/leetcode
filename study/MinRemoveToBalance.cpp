#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-removals-to-balance-array/?envType=daily-question&envId=2026-02-06

class Solution {
public:
    int minRemoval(vector<int> &nums, int k) {
        if (nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = 1;
        while (r < nums.size() && nums[r] <= nums[l] * k) {
            r++;
        }
        int cnt1 = nums.size() - (r - l);
        r = nums.size() - 1, l = r - 1;
        while (l >= 0 && nums[r] <= nums[l] * k) {
            l--;
        }
        int cnt2 = nums.size() - (r - l);
        return min(cnt1, cnt2);
    }
};
