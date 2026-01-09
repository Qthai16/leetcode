#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/

// todo: there is a better performance solutions

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        auto backtrack = [&](auto &fn, vector<int> &state, int start, int sum) {
            if (sum >= target) {
                if (sum == target)
                    ret.push_back(state);
                return;
            }
            for (auto i = start; i < candidates.size(); ) {
                state.push_back(candidates[i]);
                sum += candidates[i];
                fn(fn, state, i + 1, sum);
                // backtrack
                auto last = state[state.size() - 1];
                sum -= last;
                state.pop_back();
                do {
                    i++; // skip same elements
                } while (i < candidates.size() && last == candidates[i]);
            }
        };
        backtrack(backtrack, cur, 0, 0);
        return ret;
    }
};
