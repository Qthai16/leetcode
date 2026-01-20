#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/product-of-array-except-self/description
// solution copy from https://leetcode.com/problems/product-of-array-except-self/solutions/1342916/3-minute-read-mimicking-an-interview-by-1fpyp/?envType=study-plan-v2&envId=top-interview-150

// todo: there is a better solution without additional allocations (O(1) space complexity)
// brute force approach: O(N^2)
// divide approach: O(N), but failed if nums[i] == 0

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix product * suffix product
        vector<int> p(nums.size() + 1); // prefix product
        vector<int> s(nums.size() + 1); // suffix product
        vector<int> ret(nums.size());
        p[0] = 1;
        s[s.size() - 1] = 1;
        for (auto i = 0; i < nums.size(); i++) {
            p[i + 1] = p[i] * nums[i];
            s[nums.size() - i - 1] = s[nums.size() - i] * nums[nums.size() - i - 1];
        }
        for (auto i = 1; i <= nums.size(); i++) {
            ret[i - 1] = p[i - 1] * s[i];
        }
        return ret;
    }
};
