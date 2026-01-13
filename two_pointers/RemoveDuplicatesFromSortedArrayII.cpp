#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
// using two pointers, solution copy from: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/solutions/5792415/video-using-two-pointers-coding-exercise-twyg

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) return nums.size();
        int k = 2;
        for (auto i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
