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
    void backtrack(int start, vector<int> &nums, vector<int> &path, vector<vector<int>> &result) {
        result.push_back(path);// Add the current subset
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);             // Choose
            backtrack(i + 1, nums, path, result);// Explore
            path.pop_back();                     // Un-choose (backtrack)
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> state;
        vector<vector<int>> ret;
        int start = 0;
        backtrack(start, nums, state, ret);
        return ret;
    }
};