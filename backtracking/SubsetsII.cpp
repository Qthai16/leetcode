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
    void backtrack(int start, vector<int>& nums, vector<int>& state, vector<vector<int>>& ret) {
        ret.push_back(state);
        vector<bool> tb(21, false); // -10 <= nums[i] <= 10 (use as replacement for unordered_set)
        for (auto i = start; i < nums.size(); i++) {
            if (tb[nums[i] + 10]) continue;
            tb[nums[i] + 10] = true;
            state.push_back(nums[i]);
            backtrack(i+1, nums, state, ret);
            state.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ret;
        int start = 0;
        backtrack(start, nums, path, ret);
        return ret;
    }
};