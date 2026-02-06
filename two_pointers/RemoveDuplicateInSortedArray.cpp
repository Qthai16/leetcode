#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/submissions/detail/1883587929/

class Solution {
public:
    int oldSolution(vector<int>& nums) {
        // sliding windows
        if (nums.size() <= 1) return nums.size();
        int l = 0, r = l + 1;
        int uniqCnt = 0;
        while (l < nums.size() && r < nums.size()) {
            if (nums[l] >= nums[r]) {
                r += 1;
                continue;
            }
            if (r - l > 1) {
                // swap elements in range [l + 1, l + 1 + k] with [r, r + k], where k run from 0 -> r - l - 1
                auto k = r - l - 1;
                for (auto i = 0; i < k && r + i < nums.size(); i++) {
                    swap(nums[l + 1 + i], nums[r + i]);
                }
                l = l + 1;
                r = l + 1;
                uniqCnt += 1;
            } else {
                l += 1;
                r += 1;
                uniqCnt += 1;
            }
        }
        return uniqCnt + 1;
    }
    
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};