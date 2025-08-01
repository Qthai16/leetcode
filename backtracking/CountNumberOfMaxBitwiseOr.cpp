#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    void backtracking(int start, vector<int>& nums, vector<int>&path, int& max, int& maxcnt) {
        if (!path.empty()) {
            int cur = 0;
            for (auto i = 0; i < path.size(); i++) {
                cur |= path[i];
            }
            if (cur == max) {
                maxcnt += 1;
            } else if (cur > max) {
                max = cur;
                maxcnt = 1;
            }
        }
        for (auto i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(i + 1, nums, path, max, maxcnt);
            path.pop_back();
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max = INT_MIN, maxcnt = 0;
        vector<int> path;
        backtracking(0, nums, path, max, maxcnt);
        return maxcnt;
    }
};
