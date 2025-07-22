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
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> tb;
        priority_queue<int> h;
        int ans = -1;
        for (auto i = 0; i < arr.size(); i++) {
            tb[arr[i]] += 1;
            if (arr[i] == tb[arr[i]]) {
                h.push(arr[i]);
            }
        }
        while (!h.empty()) {
            if (tb[h.top()] == h.top()) return h.top();
            h.pop();
        }
        return -1;
    }
};