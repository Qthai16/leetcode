#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-element/description/

class Solution {
public:
    int removeElementOld(vector<int>& nums, int val) {
        // return number of remain elements in nums exclude val
        // using two pointer, if reach index where nums[i] == val, increase next pointer
        int i = 0, j = 0, cnt = 0;
        while (i < nums.size()) {
            if (nums[i] != val) {
                i++;
                if (j == i - 1) j++;
                cnt++;
                continue;
            }
            while(j < nums.size() && nums[j] == val) {
                j++;
            }
            if (j >= nums.size()) {
                // no element to swap
                break;
            }
            cnt++;
            auto tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i += 1;
            // j += 1;
        };
        return cnt;
    }

    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = 0;
        int ret = 0;
        while (r < nums.size()) {
            if (nums[r] != val) {
                if (r == l) {
                    l++;
                    r++;
                    ret++;
                } else {
                    // swap elements in ranges [l, l + k] with [r, r + k], where k run from [0, r - l]
                    auto k = r - l;
                    for (auto i = 0; i < k && r + i < nums.size(); i++) {
                        swap(nums[l + i], nums[r + i]);
                    }
                    l++;
                    r = l;
                    ret++;
                }
            } else {
                r += 1; // expand the window
            }
        }
        return ret;
    }
};