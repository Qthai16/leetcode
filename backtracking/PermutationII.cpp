// https://leetcode.com/problems/permutations-ii/

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
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.empty()) return {};
        vector<vector<int>> ret;
        vector<int> cur;
        vector<bool> selected(nums.size(), false);
        auto permuteUniq = [&](auto& fn){
            if (cur.size() == nums.size()) {
                ret.push_back(cur);
                return;
            }
            unordered_set<int> visited;
            for (auto i = 0; i < nums.size(); i++) {
                if (selected[i] || visited.count(nums[i])) continue;
                selected[i] = true;
                visited.insert(nums[i]);
                cur.push_back(nums[i]);
                fn(fn);
                cur.pop_back();
                selected[i] = false;
            }
        };
        permuteUniq(permuteUniq);
        return ret;
    }
};