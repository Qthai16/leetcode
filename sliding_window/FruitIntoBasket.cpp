#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/fruit-into-baskets/description

class Solution {
public:
    int oldSolution(vector<int> &fruits) {
        if (fruits.empty()) return 0;
        if (fruits.size() == 1) return 1;
        unordered_map<int, int> lk;
        int l = 0, r = 0;
        int ans = 0;
        while (r < fruits.size() && l < fruits.size()) {
            lk[fruits[r]] += 1;
            if (lk.size() > 2) {
                ans = max(ans, r - l);
                while (lk.size() > 2 && l < r) {
                    auto it2 = lk.find(fruits[l]);
                    if (it2 == lk.end()) {
                        break;
                    } else {
                        it2->second = it2->second - 1;
                    }
                    if (it2->second <= 0)
                        lk.erase(it2);
                    l++;
                }
            }
            r += 1;
        }
        return max(ans, r - l);
    }

    int newSolution(vector<int> &fruits) {
        if (fruits.empty()) return 0;
        const auto &f = fruits;
        unordered_map<int, int> basket;// fruit: cnt
        int l = 0, r = l + 1;
        int ret = 0;
        basket.insert({f[l], 1});
        while (r < fruits.size()) {
            basket[f[r]] += 1;// pick to basket
            if (basket.size() <= 2) {
                ret = max(r - l + 1, ret);
                // printf("choose %d:%d, len: %d\n", l, r, r - l + 1);
                r++;
                continue;
            }
            while (l < r) {
                // printf("erase f[%d]\n", l);
                basket[f[l]] -= 1;// drop from basket
                if (basket[f[l]] <= 0) {
                    basket.erase(f[l]);
                }
                l++;
                // printf("insert f[%d]\n", l);
                if (basket.size() <= 2) {
                    ret = max(r - l + 1, ret);
                    // printf("choose %d:%d, len: %d\n", l, r, r - l + 1);
                    break;
                }
            }
            r++;
        }
        return max(r - l, ret);
    }

    int totalFruit(vector<int> &fruits) {
        return newSolution(fruits);
    }
};
