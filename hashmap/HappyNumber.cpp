#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/happy-number

class Solution {
public:
    vector<int> getDigits(int n) {
        vector<int> ret;
        if (n == 0) {
            ret.push_back(0);
            return ret;
        }
        while (n > 0) {
            ret.push_back(n % 10);
            n = n / 10;
        }
        return ret;
    }

    int getNewNum(int n) {
        auto digits = getDigits(n);
        int ret = 0;
        for (const auto &d: digits) {
            ret += d * d;
        }
        return ret;
    }

    bool useHashSet(int n) {
        // use hash set to keep track of seen numbers
        unordered_set<int> seen;
        int num = n;
        bool retIsHappy = false;
        while (true) {
            auto newNum = getNewNum(num);
            if (newNum == 1) {
                retIsHappy = true;
                break;
            }
            if (seen.find(newNum) != seen.end()) {
                retIsHappy = false;
                break;
            }
            seen.insert(newNum);
            num = newNum;
        }
        return retIsHappy;
    }

    bool useFloydCycleDetection(int n) {
        // use fast and slow pointer
        auto f = [](const vector<int> digits) -> int {
            int ret = 0;
            for (const auto &v: digits) {
                ret += v * v;
            }
            return ret;
        };
        int slow = n;
        int fast = getNewNum(n);
        while (slow != fast) {
            slow = getNewNum(slow);
            fast = getNewNum(getNewNum(fast));
        }
        return slow == 1;
    }

    bool isHappy(int n) {
        // return useHashSet(n);
        return useFloydCycleDetection(n);
    }
};