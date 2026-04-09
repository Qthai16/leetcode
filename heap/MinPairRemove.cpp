#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22

class Solution {
public:
    struct Ele {
        int sum;
        pair<int, int> p;
        Ele(int s, int l, int r) : sum(s), p{l, r} {}
    };
    int solutionUsingHeap(vector<int>& nums) {
        // wrong
        auto cmp = [](const Ele& l, const Ele& r) -> bool {
            return l.sum > r.sum;
        };
        priority_queue<Ele, vector<Ele>, decltype(cmp)> h(cmp); // min heap
        for (int i = 1; i < nums.size(); i++) {
            h.push(Ele(nums[i] + nums[i-1], i - 1, i));
        }
        int ret = 0;
        unordered_map<int, int> replace; // index: sum
        while (!h.empty()) {
            auto v = h.top();
            h.pop();
            auto sum = v.sum;
            if (!replace.empty()) {
                if (replace.find(v.p.first) != replace.end()) {
                    sum = sum - nums[v.p.first] + replace[v.p.first];
                }
                if (replace.find(v.p.second) != replace.end()) {
                    sum = sum - nums[v.p.second] + replace[v.p.second];
                }
            }
            if ((h.empty() || sum <= h.top().sum) && v.p.first == 0 && v.p.second == 1)
                break;
            ret += 1;
            replace[v.p.first] = sum;
            replace[v.p.second] = sum;
        }
        return ret;
    }
    int minimumPairRemoval(vector<int>& nums) {

    }
};
