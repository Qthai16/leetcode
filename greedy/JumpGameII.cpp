#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-ii

// Input: nums = [2,3,1,1,4]
// output: 2
// solution using greedy BFS or dynamic programing

class Solution {
public:
    int jump(vector<int> &nums) {
        // guarantee to reach nums.size() - 1
        // return minimum jump need
        // maybe using max heap
        using MaxHeap = std::priority_queue<pair<int, int>>;// gap, ind
        if (nums.size() == 1) return 1;
        MaxHeap h;
        int goal = nums.size() - 1, cur = goal - 1, ret = 0, acc = 0;
        while (goal > 0 && cur >= 0) {
            // loop all possible pos that can jump to goal
            if (cur + nums[cur] >= goal) {
                h.push({cur + nums[cur] + acc, cur});
                acc++;
                cur--;
                continue;
            }
            // here we cannot reach goal any more
            auto v = h.top();
            goal = v.second;
            cur = goal - 1;
            acc = 0;
            printf("%d, %d\n", goal, cur);
            ret += 1;
            MaxHeap emptyh;
            h.swap(emptyh);
        }
        return ret + 1;
    }
};