#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int> &nums) {
        // set goal == nums.size() - 1, then set cur = goal - 1.
        // For each current index, check if maximum len can reach goal. If true, set new goal to cur, else decrease current index and retry
        if (nums.size() == 1) return true;
        int goal = nums.size() - 1, cur = goal - 1;
        while (goal > 0 && cur >= 0) {
            if (cur + nums[cur] < goal) { // cannot reach goal
                cur--;
                continue;
            }
            goal = cur;
            cur = goal - 1;
        }
        return goal == 0;
    }
};
