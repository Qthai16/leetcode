#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        int p = 1;
        string s{'a'};
        while (k > s.size()) {
            auto csize = s.size();
            for (auto i = 0; i < csize; i++) {
                s += s[i] + 1 > 'z' ? 'a' : s[i] + 1;
            }
            // printf("%s\n", s.c_str());
        }
        return s[k-1];
    }
};