#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/ransom-note/description

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // used vector for better performance than unordered_map
        vector<int> tb;
        tb.resize('z' - 'a' + 1, 0);
        for (const auto& c : magazine) {
            tb[c - 'a'] += 1;
        }
        for (const auto& c : ransomNote) {
            auto& v = tb[c - 'a'];
            if (v <= 0) return false;
            v -= 1;
        }
        return true;
    }
};
