#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ret;
        list<char> st;
        list<string> cur;
        for (const auto& c : s) {
            if (c == '(') {
                st.push_back(c);
                cur.push_back({});
            } else if (c == ')') {
                if (st.empty())
                    continue; // this is invalid
                std::string tmp;
                // todo: try come up with a better solution without string allocation
                if (!cur.empty() && !cur.back().empty()) {
                    tmp = "(" + cur.back() + ")";
                } else tmp = "()";
                cur.pop_back();
                st.pop_back();
                if (!cur.empty()) cur.back() += std::move(tmp);
                else ret += std::move(tmp);
            } else if (c >= 'a' && c <= 'z') {
                if (cur.empty()) cur.push_back({});
                cur.back() += c;
            }
        }
        while (!cur.empty()) {
            if (!cur.front().empty()) {
                ret += cur.front();
            }
            cur.pop_front();
        }
        return ret;
    }
};