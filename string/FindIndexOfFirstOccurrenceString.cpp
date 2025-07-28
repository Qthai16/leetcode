#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // return haystack.find(needle);
        if (needle.size() > haystack.size())
            return -1;
        int n = 0, h = 0;
        unordered_map<char, deque<int>> tb;
        while (n < needle.size() && h < haystack.size()) {
            auto& v = tb[haystack[h]];
            if (v.empty() || v[v.size() - 1] < h)
                v.push_back(h);
            if (haystack[h] == needle[n]) {
                h++;
                n++;
                continue;
            }
            n = 0;
            auto it = tb.find(needle[0]);
            if (it != tb.end() && !it->second.empty()) {
                tb[needle[0]].pop_front();
                h = (!tb[needle[0]].empty()) ? tb[needle[0]][0] : h + 1;
            } else h += 1;
            // printf("h reset to %d\n", h);
        }
        return n >= needle.size() ? h - needle.size() : -1;
    }
};