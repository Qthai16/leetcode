#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/trionic-array-i/?envType=daily-question&envId=2026-02-03

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = INT_MIN, q = INT_MIN;
        bool inc = true;
        int cnt = 0;
        if (nums.size() == 2) return false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return false;
            if (inc) {
                if (nums[i] > nums[i-1]) continue;
                inc = !inc;
                cnt++;
                p = i - 1;
            } else {
                if (nums[i] < nums[i-1]) continue;
                inc = !inc;
                cnt++;
                q = i - 1;
            }
        }
        return p > 0 && q != INT_MIN && cnt == 2;
    }
};