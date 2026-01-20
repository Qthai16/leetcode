#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-window-substring/description

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return {};
        if (t.size() == 0) return {};
        unordered_map<int, int> tb; // could use vector<char> for optimization
        for (int i = 0; i < t.size(); i++) {
            tb[t[i]] += 1;
        }
        int l = 0, r = l, head = l;
        bool first = false;
        int minsize = INT_MAX;
        int counter = t.size();
        string ret;
        while (r < s.size()) {
            if (!first && tb.find(s[l]) == tb.end()) {
                l++;
                r++;
            } else if (first) {
                if (tb[s[r]]-- > 0) // char in t, decrease counter
                    counter--;
                r++;
            } else {
                if (tb[s[l]]-- > 0) // char in t, decrease counter
                    counter--;
                first = true; // first char in t found
                r++;
            }
            while (counter == 0) { // we found a window, shrink the window until it's invalid
                if (r - l < minsize) {
                    minsize = r - l;
                    head = l;
                }
                // printf("found window: %s\n", s.substr(l, r));
                if (tb[s[l]]++ == 0) // this char is in t, make the window invalid again
                    counter++;
                l++;
            }
        }
        return minsize == INT_MAX ? "" : s.substr(head, minsize);
    }
};
