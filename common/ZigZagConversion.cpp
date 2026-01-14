#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/zigzag-conversion/description

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return s;
        vector<string> v(numRows);
        int i = 0;
        int a = 1;
        for (const auto& c : s) {
            v[i] += c;
            i += a;
            if (i == numRows || i == -1) {
                a = -1*a;
                i += 2*a;
            }
        }
        string ret;
        for (auto i = 0; i < v.size(); i++) {
            ret += v[i];
        }
        return ret;
    }
};
