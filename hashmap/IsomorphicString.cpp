#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool checkIsomorphic(const string& a, const string& b) {
        unordered_map<char, char> tb;
        for (auto i = 0; i < a.size(); i++) {
            auto it = tb.find(a[i]);
            if (it == tb.end()) {
                tb[a[i]] = b[i];
                continue;
            }
            if (it->second == b[i]) continue;
            return false;
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        return checkIsomorphic(s, t) && checkIsomorphic(t, s);
    }
};
