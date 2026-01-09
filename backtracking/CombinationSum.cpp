#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/

// candidates: [2, 3, 4]
// target: 6
// expect: [2, 2, 2], [3, 3], [2, 4]

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        auto backtrack = [&](auto &fn, vector<int> &state, int start, int sum) {
            if (sum >= target) {
                if (sum == target) {
                    ret.push_back(state);
                }
                return;
            }
            for (auto i = start; i < candidates.size(); i++) {
                state.push_back(candidates[i]);
                sum +=  candidates[i];
                fn(fn, state, i, sum);
                // backtrack
                sum -= candidates[i];
                state.pop_back();
            }
        };
        backtrack(backtrack, cur, 0, 0);
        return ret;
    }
};
