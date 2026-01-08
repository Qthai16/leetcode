#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // if (n == 1) return vector<string>{string{"()"}};
        string state;
        vector<string> ret;
        int i = 0, j = 0;
        auto backtrack = [&](auto &fn, int i, int j, string s) {
            if (s.size() == n * 2) {
                ret.push_back(s);
                return;
            }
            if (i < n) {
                fn(fn, i + 1, j, s + '(');
            }
            if (j < i) {
                fn(fn, i, j + 1, s + ')');
            }
        };
        backtrack(backtrack, i, j, state);
        return ret;
    }
};