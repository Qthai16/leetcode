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

using namespace std;

// https://leetcode.com/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-05

class Solution {
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        // naive approach using bruteforce. Time complexity O(N2)
        // for O(N*logN) approach, use a segment tree
        // https://leetcode.com/problems/fruits-into-baskets-ii/solutions/7046674/on-logn-solution-segment-tree-by-r_patel-2twm/
        int selectCnt = 0, j = 0;
        vector<bool> selected(fruits.size(), false);
        for (auto i = 0; i < fruits.size(); i++) {
            // int loopcnt = 0;
            int j = 0;
            while ((selected[j] || baskets[j] < fruits[i])) {
                j++;
                if (j == baskets.size()) break;
            }
            if (j < baskets.size()) {
                // not selected and baskets[j] < fruits[i]
                // printf("fruits: %d, basket: %d\n", i, j);
                selected[j] = true;
                selectCnt += 1;
            }
        }
        return static_cast<int>(fruits.size()) - selectCnt;
    }
};