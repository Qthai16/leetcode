#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> index{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> val{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        // map<int, string> lk{
        //     {1, "I"},
        //     {4, "IV"},
        //     {5, "V"},
        //     {9, "IX"},
        //     {10, "X"},
        //     {40, "XL"},
        //     {50, "L"},
        //     {90, "XC"},
        //     {100, "C"},
        //     {400, "CD"},
        //     {500, "D"},
        //     {900, "CM"},
        //     {1000, "M"},
        // };
        string ans;
        while (num > 0) {
            // printf("%d\n", num);
            auto it = lower_bound(index.begin(), index.end(), num);
            if  (it == index.end()) {
                auto div = int(num/index.back());
                for (auto i = 0; i < div; i++) {
                    ans += val.back();
                }
                num -= div*index.back();
            } else {
                auto pos = it - index.begin();
                if (index[pos] == num) {
                    ans += val[pos];
                    num -= index[pos];
                } else {
                    // back one iter
                    if (pos != 0) pos -= 1;
                    auto div = int(num/index[pos]);
                    for (auto i = 0; i < div; i++) {
                        ans += val[pos];
                    }
                    // printf("%d\n", num);
                    num -= div*(index[pos]);
                }
            }
        }
        return ans;
    }
};