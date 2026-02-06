#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/summary-ranges/description

class Solution {
public:
    vector<string> oldSolution(vector<int>& nums) {
        vector<string> ret;
        stack<pair<int64_t, int64_t>> s;
        auto i64min = INT64_MIN;
        for (const auto& num : nums) {
            int64_t v = static_cast<int64_t>(num);
            if (s.empty()) {
                s.push({v, i64min});
                continue;
            }
            if (s.top().second != i64min && v - s.top().second == 1) {
                s.top().second = v;
                continue;
            }
            if (s.top().second != i64min) {
                std::string str;
                str += std::to_string(s.top().first) + "->" + std::to_string(s.top().second);
                ret.push_back(str);
                s.pop();
                s.push({v, i64min});
                continue;
            }
            if (v - s.top().first == 1) {
                s.top().second = v;
                continue;
            }
            ret.push_back(std::to_string(s.top().first));
            s.pop();
            s.push({v, i64min});
        }
        vector<string> remains;
        while (!s.empty()) {
            auto v = s.top();
            std::string str;
            if (v.second != i64min) {
                str += std::to_string(v.first) + "->" + std::to_string(v.second);
                remains.push_back(str);
            } else {
                str += std::to_string(v.first);
                remains.push_back(str);
            }
            s.pop();
        }
        ret.insert(ret.end(), remains.rbegin(), remains.rend());
        return ret;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<pair<int, int>> ranges;
        for (const auto& n : nums) {
            if (ranges.empty()) {
                ranges.push_back({n, INT_MIN});
                continue;
            }
            auto last = ranges[ranges.size() - 1].second != INT_MIN ? ranges[ranges.size() - 1].second : ranges[ranges.size() - 1].first;
            if (last == INT_MAX) {
                ranges.push_back({n, INT_MIN});
                continue;
            }
            if (last + 1 == n) { // last + 1 instead of n - last for integer overflow
                ranges[ranges.size() - 1].second = n;
            } else {
                ranges.push_back({n, INT_MIN});
            }
        }
        vector<string> ret;
        for (auto& p : ranges) {
            string tmp;
            tmp += std::to_string(p.first);
            if (p.second != INT_MIN) tmp += string{"->"} + std::to_string(p.second);
            ret.push_back(std::move(tmp));
        }
        return ret;
    }
};