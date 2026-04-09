#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07

class Solution {
public:
    // int minimumDeletions(string s) {
    //     int fa = INT_MIN, lasta = INT_MIN, fb = INT_MIN, lastb = INT_MIN;// first and last a, first and last b
    //     for (int i = 0; i < s.size(); i++) {
    //         auto c = s[i];
    //         if (c == 'a') {
    //             if (fa == INT_MIN) fa = i;
    //             lasta = max(lasta, i);
    //         } else if (c == 'b') {
    //             if (fb == INT_MIN) fb = i;
    //             lastb = max(lastb, i);
    //         }
    //     }
    //     int invA = 0, invB = 0;
    //     for (int i = fa; i <= lasta; i++) {
    //         if (s[i] == 'b') invB++;
    //     }
    //     for (int i = fb; i <= lastb; i++) {
    //         if (s[i] == 'a') invA++;
    //     }
    //     return min(invA, invB);
    // }
    int minimumDeletions(string s) {
        int l = 0, r = s.size() - 1, inva = 0, invb = 0;
        while (l < r) {
            if (s[l] == 'a') {
                l++;
            } else {
                invb++;
            }
            if (s[r] == 'b') {
                r--;
            } else {
                inva++;
            }
        }
        return inva + invb;
    }
};
