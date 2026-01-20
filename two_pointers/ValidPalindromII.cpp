#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-palindrome-ii/description

class Solution {
public:
    bool palHelper(const string& s, int start, int end) {
        int l = start, r = end;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if (s.size() <= 2) return true;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }
            return palHelper(s, l, r - 1) || palHelper(s, l + 1, r);
        }
        return true;
    }
};
