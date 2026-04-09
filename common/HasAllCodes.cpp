#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/?envType=daily-question&envId=2026-02-23

class Solution {
public:
    int toInt(const string& s) {
        return stoi(s, nullptr, 2);
    }

    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        unordered_set<int> setNums;
        for (int i = 0; i <= s.size() - k; i++) {
            setNums.insert(toInt(s.substr(i, k)));
        }
        for (int num = 0; num < (1 << k); num++) {
            if (setNums.find(num) == setNums.end()) {
                // printf("miss %d\n", num);
                return false;
            }
        }
        return true;
    }
};