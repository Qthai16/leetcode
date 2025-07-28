// https://leetcode.com/problems/permutations

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

// class Permutation {
//     vector<vector<int>> ret;
//     vector<int> curr;
//     vector<int> selected;
// public:
//     Permutation() = default;
//     ~Permutation() = default;

// public:
//     vector<vector<int>> permute(vector<int> &nums) {
//         selected.resize(nums.size());
//         permuteByIndex(0, nums);
//         return ret;
//     }

//     void permuteByIndex(int ind, vector<int> &nums) {
//         if (ind >= nums.size()) {
//             ret.push_back(curr);
//             return;
//         }
//         for (auto i = 0; i < nums.size(); i++) {
//             if (selected[i]) continue;
//             selected[i] = 1;
//             curr.push_back(nums[i]);
//             permuteByIndex(ind + 1, nums);
//             // backtracking
//             // curr.erase(remove(curr.begin(), curr.end(), nums[i]));
//             curr.pop_back();
//             selected[i] = 0;
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> selected(nums.size(), false);
        vector<int> curr;
        vector<vector<int>> ret;
        auto permuteImpl = [&](auto& fn){
            if (curr.size() == nums.size()) {
                ret.push_back(curr);
                return;
            }
            for (auto i = 0; i < nums.size(); i++) {
                if (selected[i]) continue;
                selected[i] = true;
                curr.push_back(nums[i]);
                fn(fn);
                curr.pop_back();
                selected[i] = false;
            }
        };
        permuteImpl(permuteImpl);
        return ret;
    }
};