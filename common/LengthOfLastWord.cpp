#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastCnt = 0, curCnt = 0;
        for (auto &c : s) {
            if (c == ' ') {
                lastCnt = curCnt != 0 ? curCnt : lastCnt;
                curCnt = 0;
                continue;
            }
            curCnt += 1;
        }
        return curCnt != 0 ? curCnt : lastCnt;
    }
};