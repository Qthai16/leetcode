#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate_copy(vector<int> &nums, int k) {
        vector<int> ret;
        ret.resize(nums.size());
        auto pos = nums.size() - k;
        for (auto i = pos; i < nums.size(); i++) {
            ret[i - pos] = nums[i];
        }
        for (auto i = 0; i < pos; i++) {
            ret[i + k] = nums[i];
        }
        swap(nums, ret);
    }

    void reverse(vector<int> &nums, int l, int len) {
        if (len > nums.size() - l) len = nums.size() - l;
        // start index, array len
        auto r = l + len - 1;
        for (auto i = 0; i < len/2; i++) {
            swap(nums[l + i], nums[r - i]);
        }
    }

    void rotate_in_place(vector<int> &nums, int k) {
        // three reverse method
        reverse(nums, 0, nums.size()); // entire array
        reverse(nums, 0, k); // left half
        reverse(nums, k, nums.size() - k); // right half
    }
public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        // rotate_copy(nums, k);
        rotate_in_place(nums, k);
    }
};