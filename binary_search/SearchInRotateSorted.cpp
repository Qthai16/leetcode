#include <bits/stdc++.h>

using namespace std;

// [6,7,1,2,3,4,5], target 6

class Solution {
    int binary_search(const vector<int> &nums, int low, int high, int target) {
        int l = low, r = high;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l < high && nums[l] == target ? l : -1;
    }

public:
    int search(vector<int> &nums, int target) {
        // nums is left rotated by k
        // algorithm must be O(logN)
        int l = 0, r = nums.size();
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] <= nums[r - 1]) {// right half is sorted
                if (nums[mid] < target && target <= nums[r - 1]) {
                    l = mid + 1; // move right
                } else {
                    r = mid; // // move left
                }
            } else {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid; // move left
                } else {
                    l = mid + 1; // move right
                }
            }
        }
        if (l < nums.size() && nums[l] == target) {
            return l;
        } else
            return -1;
    }
};