#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-watch/description/?envType=daily-question&envId=2026-02-17

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> hour = {8, 4, 2, 1};
        vector<int> minutes = {32, 16, 8, 4, 2, 1};
        int n = hour.size() + minutes.size();
        turnedOn = min(turnedOn, n);

        void backtracking(vector<string> & ret, const vector<int> &hour, const vector<int> &minutes, int cnt, int turnOn) {
            int h = hour.size(), m = minutes.size();
            string cur;
            if (cnt == turnOn) {
                ret.push_back();
            }
        }
    }
};