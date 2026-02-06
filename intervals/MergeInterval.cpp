#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> oldSolution(vector<vector<int>> &intervals) {
        std::vector<std::pair<int, int>> sorted;
        for (const auto &v: intervals) {
            sorted.push_back(std::make_pair(v[0], v[1]));
        }
        std::sort(sorted.begin(), sorted.end());
        vector<vector<int>> ret;
        for (auto it = sorted.begin(); it != sorted.end();) {
            auto next = std::next(it, 1);
            if (next == sorted.end()) {
                ret.push_back(std::vector<int>{it->first, it->second});
                break;
            }
            if (it->second >= next->first) {// merge it
                // printf("merge: [%d, %d] vs [%d, %d]\n", it->first, it->second, next->first, next->second);
                next->first = it->first;
                next->second = std::max(next->second, it->second);
                it = next;
            } else {
                ret.push_back(std::vector<int>{it->first, it->second});
                it++;
            }
        }
        return ret;
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        auto& ranges = intervals;
        std::sort(ranges.begin(), ranges.end(), [](const auto& l, const auto& r) -> bool {
            return l[0] != r[0] ? l[0] < r[0] : l[1] < r[1];
        });
        vector<vector<int>> ret;
        for (int i = 0, next = i + 1; i < ranges.size();) {
            if (i == ranges.size() - 1 || next >= ranges.size()) {
                // last ranges or no more range to check, insert current range and return
                ret.push_back(ranges[i]);
                break;
            }
            if (ranges[i][1] >= ranges[next][0]) { // overlapped, extend current end
                ranges[i][1] = max(ranges[i][1], ranges[next][1]);
                next++;
                continue;
            }
            // not overlapped anymore, insert current range and continue
            ret.push_back(ranges[i]);
            i = next;
            next = i + 1;
        }
        return ret;
    }
};
