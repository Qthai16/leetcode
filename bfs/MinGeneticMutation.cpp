#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=top-interview-150

// ["AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"]
// end: "AATTCCGG"
// start: "AACCTTGG"

// ["AACCGATT","AACCGATA","AAACGATA","AAACGGTA"]
// "AAACGGTA"
// "AACCGGTT"


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        auto it = find(bank.begin(), bank.end(), endGene);
        if (it == bank.end()) return -1;
        int i = 0, n = startGene.size();
        int ret = 0;
        unordered_map<char, char> convert;
        while (i < n) {
            if (startGene[i] != endGene[i]) {
                ret++;
                if (convert.find(endGene[i]) != convert.end() && convert[endGene[i]] == startGene[i])
                    return -1;
                convert[startGene[i]] = endGene[i];
            }
            i++;
        }
        return ret;
    }
};
