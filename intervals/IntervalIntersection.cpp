#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> oldSolution(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        using Intv = std::pair<int, int>;
        using InitList = std::initializer_list<int>;
        std::vector<Intv> sorted;
        auto maxSize = std::max(firstList.size(), secondList.size());
        for (auto i = 0; i < maxSize; i++) {
            if (i < firstList.size())
                sorted.push_back({firstList[i][0], firstList[i][1]});
            if (i < secondList.size())
                sorted.push_back({secondList[i][0], secondList[i][1]});
        }
        std::sort(sorted.begin(), sorted.end());
        vector<vector<int>> ret;
        for (auto it = sorted.begin(); it != sorted.end();) {
            auto next = std::next(it);
            if (next == sorted.end()) break;
            if (*it == *next) { // same intervals, eg: [1,2] vs [1,2]
                ret.push_back({it->first, it->second});
                it = next;
            } else if (it->second >= next->first) {
                if (it->second == next->first) {
                    ret.push_back({it->second, it->second});
                } else {
                    ret.push_back({next->first, std::min(it->second, next->second)});
                    // insert the remain interval to list
                    next->first = std::min(it->second, next->second);
                    next->second = std::max(it->second, next->second);
                }
                it = next;
            } else {
                it++;
            }
        }
        return ret;
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> all;
        auto cmp = [](const vector<int>& l, const vector<int>& r) -> bool {
            return l[0] != r[0] ? l[0] < r[0] : l[1] < r[1];
        };
        int i = 0, j = 0;
        while (i < firstList.size() || j < secondList.size()) {
            if (i < firstList.size()) all.push_back(firstList[i++]);
            if (j < secondList.size()) all.push_back(secondList[j++]);
        }
        sort(all.begin(), all.end(), cmp);
        vector<vector<int>> overlapped;
        for (int i = 0, next = i + 1; i < all.size();) {
            while (next < all.size() && all[i][1] >= all[next][0]) { // current interval still overlapped with next interval
                vector<int> v{max(all[i][0], all[next][0]), min(all[i][1], all[next][1])}; // overlapped part
                overlapped.push_back(v);
                all[i][1] = max(all[i][1], all[next][1]); // update current interval end
                next++;
            }
            i = next;
            next = i + 1;
        }
        return overlapped;
    }
};