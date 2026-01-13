#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> tb;
        for (auto i = 0; i < nums.size(); i++) {
            auto it = tb.find(nums[i]);
            if (it == tb.end()) {
                tb[nums[i]] = i;
                continue;
            }
            if (abs(i - it->second) <= k)
                return true;
            it->second = i;
        }
        return false;
    }
};