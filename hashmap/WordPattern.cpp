#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-pattern/description

class Solution {
public:
    template<typename T>
    void print_vec(const std::vector<T>& v) {
        std::cout << "[";
        for (const auto& n : v) {
            std::cout << n << ", ";
        }
        std::cout << "]" << std::endl;
    }
    template<typename A, typename B>
    bool matchPattern(const std::vector<A>& a, const std::vector<B>& b) {
        if (a.size() != b.size()) return false;
        unordered_map<A, B> tb;
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
    bool wordPattern(string pattern, string s) {
        vector<string> sv;
        std::string cur;
        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!cur.empty()) {
                    sv.push_back(cur);
                    cur.clear();
                }
                continue;
            }
            cur += s[i];
        }
        if (!cur.empty()) sv.push_back(cur);
        std::vector<char> pat;
        for (auto i = 0; i < pattern.size(); i++) {
            pat.push_back(pattern[i]);
        }
        print_vec(sv);
        return matchPattern(pat, sv) && matchPattern(sv, pat);
    }
};