#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty() || prices.size() == 1) return 0;
        int l = 0, r = l + 1;
        int ans = 0;
        while (r + 1 < prices.size() && r < prices.size()) {
            if (prices[r] <= prices[l]) {
                l = r;
                r = l + 1;
                continue;
            }
            if (prices[r + 1] >= prices[r]) {
                r += 1;
            } else {
                // price drop at next day, sell the stock at this day
                auto tmp = prices[r] - prices[l];
                ans += tmp > 0 ? tmp : 0;
                l = r;
                r += 1;
            }
        }
        if (r == prices.size()) r -= 1;
        auto tmp = prices[r] - prices[l];
        ans += tmp > 0 ? tmp : 0;
        return ans;
    }
};