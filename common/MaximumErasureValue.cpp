// https://leetcode.com/problems/maximum-erasure-value/description

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    // int maximumUniqueSubarray(vector<int> &nums) {
    // // same idea with sliding windows + prefix sum
    //     unordered_map<int, int> tb; // val: ind
    //     int ans = 0;
    //     int lastInd = 0;
    //     int cursum = 0;
    //     for (auto i = 0; i < nums.size(); i++) {
    //         const auto &val = nums[i];
    //         auto it = tb.find(val);
    //         if (it != tb.end()) {
    //             ans = max(ans, cursum);
    //             auto ind = it->second;
    //             for (auto j = lastInd; j <= ind; j++) {
    //                 tb.erase(nums[j]);
    //                 cursum -= nums[j];
    //             }
    //             lastInd = ind + 1;
    //         }
    //         tb[val] = i;
    //         cursum += val;
    //     }
    //     return max(ans, cursum);
    // }

    int maximumUniqueSubarray(vector<int> &nums) {
        // sliding windows + prefix sum
        int ans = 0;
        vector<int> presum(nums.size() + 1);        
        for (auto i = 0; i < nums.size(); i++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        int l = 0, r = 0;
        unordered_set<int> tb;
        while (r < nums.size()) {
            const auto &val = nums[r];
            if (tb.find(val) != tb.end()) {
                ans = max(ans, presum[r] - presum[l]);
                while (nums[l] != nums[r]) {
                    tb.erase(nums[l]);
                    l++;
                }
                tb.erase(nums[l]);
                l++;
            }
            tb.insert(val);
            r++;
        }
        return max(ans, presum[r] - presum[l]);
    }
};
