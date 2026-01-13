#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> tb;
        for (auto i = 0; i < s.size(); i++) {
            tb[s[i]] += 1;
            tb[t[i]] -= 1;
        }
        for (const auto& [c, f] : tb) {
            if (f != 0) return false;
        }
        return true;
    }
};