#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty() || prices.size() == 1) return 0;
        int l = 0, r = l + 1;
        int ans = 0;
        while (r + 1 < prices.size() && r < prices.size()) {
            if (prices[r] <= prices[l]) { // price is lower, buy today (l)
                l = r;
                r = l + 1;
                continue;
            }
            if (prices[r + 1] >= prices[r]) { // next day price is higher, continue
                r += 1;
            } else { // price drop at next day, sell stock today (r)
                auto tmp = prices[r] - prices[l];
                ans += tmp > 0 ? tmp : 0;
                l = r;
                r += 1;
            }
        }
        if (r == prices.size()) r -= 1;
        // check final option
        auto tmp = prices[r] - prices[l];
        ans += tmp > 0 ? tmp : 0;
        return ans;
    }
};