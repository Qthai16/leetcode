#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        int si = 0, ti = 0;
        while (ti < t.size()) {
            if (t[ti] == s[si]) {
                ti += 1;
                si += 1;
                continue;
            }
            ti += 1;
        }
        return si == s.size();
    }
};
