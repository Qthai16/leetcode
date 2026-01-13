#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        const auto& h = height;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            max = std::max(max, (r-l)*std::min(h[l], h[r]));
            if (h[l] <= h[r]) l += 1;
            else r -= 1;
        }
        return max;
    }
};