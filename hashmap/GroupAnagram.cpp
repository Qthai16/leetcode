#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/group-anagrams/description
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // naive approach, O(N*(O(M) + O(K)))
        using CharVec = std::vector<int>;
        using RetVal = vector<string>;
        vector<pair<CharVec, RetVal>> tb;
        for (const auto& str : strs) {
            CharVec tmp('z' - 'a' + 1, 0);
            for (auto c : str) {
                tmp[c - 'a'] += 1;
            }
            auto it = std::find_if(tb.begin(), tb.end(), [tmp](const auto& e) -> bool {
                return e.first == tmp;
            });
            if (it == tb.end()) {
                tb.push_back({tmp, RetVal{str}});
            } else {
                (*it).second.push_back(str);
            }
        }
        vector<vector<string>> ret(tb.size(), vector<string>{});
        for (int i = 0; i < tb.size(); i++) {
            swap(ret[i], tb[i].second);
        }
        return ret;
    }
};
