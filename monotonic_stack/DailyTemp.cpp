#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/daily-temperatures/
// next greater: stack giam (top stack la min)
// next smaller: stack tang (top stack la max)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const auto& t = temperatures;
        vector<int> ret(t.size(), 0);
        stack<int, list<int>> mns;
        for (int i = 0; i < t.size(); i++) {
            while (!mns.empty() && t[i] > t[mns.top()]) {
                ret[mns.top()] = i - mns.top();
                mns.pop();
            }
            mns.push(i);
        }
        return ret;
    }

    vector<int> oldSolution(vector<int>& temperatures) {
        const auto &t = temperatures;
        vector<int> ret;
        ret.resize(t.size(), 0);
        stack<int> s; // next greater --> decreasing
        int i = 0;
        while (i < t.size()) {
            while(!s.empty() && t[s.top()] < t[i]) {
                ret[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
            i++;
        }
        return ret;
    }
};
