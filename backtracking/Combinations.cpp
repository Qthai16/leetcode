#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> state;
        auto backtrack = [&](auto &fn, int start) {
            if (state.size() == k) {
                ret.push_back(state);
                return;
            }
            for (auto i = start; i <= n; i++) {
                state.push_back(i);
                fn(fn, i + 1);
                state.pop_back();
            }
        };
        int start = 1;
        backtrack(backtrack, start);
        return ret;
    }
};