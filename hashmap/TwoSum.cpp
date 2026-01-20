#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> tb; // num: index
        for (int i = 0; i < nums.size(); i++) {
            auto n = nums[i];
            auto remains = target - n;
            auto iter = tb.find(remains);
            if (iter == tb.end()) {
                tb[n] = i;
                continue;
            }
            return {iter->second, i};
        }
        return {};
    }
};
