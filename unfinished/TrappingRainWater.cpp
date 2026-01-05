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
// input: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
// output: 6

// next greater: min stack

class Solution {
public:
    int trap(vector<int> &height) {
        deque<int> s;
        int ans = 0;
        
        for (auto i = 0; i < height.size(); i++) {
            if (!s.empty() && height[i] >= height[s.back()] && height[s.front()] >= height[i]) {
                int sub = 0;
                auto indStart = s.front();
                auto w = i - s.front() - 1;                // width
                auto h = min(height[s.front()], height[i]);// min height
                while (!s.empty()) {
                    auto ind = s.back();
                    if (ind != indStart && height[ind] > 0) sub += height[ind];// width 1
                    s.pop_back();
                }
                auto trapVal = w * h - sub;
                if (trapVal > 0) {
                    ans += trapVal;
                    printf("%d, %d, %d\n", indStart, i, trapVal);
                    s.clear();
                }
            }
            s.push_back(i);
            // if (height[i] > 0 && i != s.front()) sub += height[i];
        }
        // if (!s.empty()) {
        //     // while (!s.empty() && height[s.front()] > height[s.back()]) {
        //     //     s.pop_front();
        //     //     s.pop_back();
        //     // }
        //     // printf("%d, %d\n", s.front(), s.back());
        //     int sub = 0;
        //     int istart = s.front();
        //     int iback = s.back();
        //     auto w = s.back() - s.front() - 1;
        //     auto h = min(height[s.front()], height[s.back()]);
        //     while (!s.empty()) {
        //         auto i = s.back();
        //         if (i != istart && i != iback && height[i] > 0) sub += height[i];// width 1
        //         s.pop_back();
        //     }
        //     if (w > 0 && h > 0)
        //         ans += w * h - sub;
        // }
        return ans;
    }
};