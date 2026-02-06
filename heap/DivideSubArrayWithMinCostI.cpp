#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/?envType=daily-question&envId=2026-02-01

class Solution {
public:
    // todo: better solution, could find min and second min in one pass
    int minimumCost(vector<int>& nums) {
        priority_queue<int> h; // max heap
        for (int i = 1; i < nums.size(); i++) {
            h.push(nums[i]);
            while (h.size() > 2) {
                h.pop();
            }
        }
        int cost = 0;
        while (!h.empty()) {
            cost += h.top();
            h.pop();
        }
        return cost + nums[0];
    }
};
