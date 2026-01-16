#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/ipo/description

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        // min heap for capital, max heap for profit
        using CapPair = pair<int, int>; // cap: profit
        auto capPairCmp = [](const CapPair& l, const CapPair& r) -> bool {
            return l.first > r.first;
        };
        priority_queue<CapPair, vector<CapPair>, decltype(capPairCmp)> minCap(capPairCmp);
        priority_queue<int> maxh; // max heap for profit
        int n = profits.size();
        for (auto i = 0; i < n; i++) {
            minCap.push(CapPair{capital[i], profits[i]});
        }
        for (auto i = 0; i < k; i++) {
            while (!minCap.empty() && minCap.top().first <= w) {
                maxh.push(minCap.top().second);
                minCap.pop();
            }
            if (maxh.empty()) break; // no available project to choose
            w += maxh.top();
            maxh.pop();
            // all remain projects with max profit in maxh, so continue
        }
        return w;
    }
};
