#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> oldSolution(vector<int> &prices) {
        vector<int> smaller;
        smaller.resize(prices.size(), -1);
        deque<int> s;
        const auto &a = prices;
        for (auto i = 0; i < a.size(); i++) {
            while (!s.empty() && a[i] <= a[s.back()]) {
                smaller[s.back()] = a[i];
                s.pop_back();
            }
            s.push_back(i);
        }
        for (auto i = 0; i < prices.size(); i++) {
            prices[i] = smaller[i] != -1 ? prices[i] - smaller[i] : prices[i];
        }
        return prices;
    }

    vector<int> finalPrices(vector<int> &prices) {
        vector<int> smaller;
        smaller.resize(prices.size(), -1);
        stack<int, list<int>> s;
        const auto &a = prices;
        for (auto i = 0; i < a.size(); i++) {
            while (!s.empty() && a[i] <= a[s.top()]) {
                smaller[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
        for (auto i = 0; i < prices.size(); i++) {
            prices[i] = smaller[i] != -1 ? prices[i] - smaller[i] : prices[i];
        }
        return prices;
    }
};