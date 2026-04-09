#include <bits/stdc++.h>
using namespace std;

// solution use interval tree

// https://leetcode.com/problems/range-sum-query-mutable/description/

class NumArray {
public:
    NumArray(vector<int> &nums) : nums_(nums), sum(), delta() {
        sum.resize(nums.size() + 1);
        for (auto i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
    }

    void update(int index, int val) {
        delta[index] = val - nums_[index];
    }

    int sumRange(int left, int right) {
        auto val = sum[right + 1] - sum[left];
        for (auto [i, d] : delta) {
            if (left <= i && i <= right) {
                val += d;
            }
        }
        return val;
    }

private:
    vector<int> nums_;
    vector<int> sum;
    map<int, int> delta; // sum ind: delta
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */