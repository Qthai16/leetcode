#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
    int floydCycle(vector<int> &nums) {
        // chatGPT suggest this
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // here we got the cycle (meeting point)
        // reset slow and move slow + fast one at a time
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

    int findDuplicate(vector<int> &nums) {
        return floydCycle(nums);
    }
};