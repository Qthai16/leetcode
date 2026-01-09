#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    struct Ele {
        int x;
        int y;
    };
    enum State : int8_t {
        EMPTY = 0,
        FRESH = 1,
        ROTTEN = 2,
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Ele> q;
        int fresh = 0;
        int ret = 0;
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == State::ROTTEN) {
                    q.push({i, j});
                } else if (grid[i][j] == State::FRESH) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) return 0; // no fresh orange from the start
        auto maxj = grid[0].size();
        auto maxi = grid.size();
        while (!q.empty()) {
            auto len = q.size();
            for (auto i = 0; i < len; i++) {
                auto ele = q.front();
                q.pop();
                // right
                if (ele.y + 1 < maxj && grid[ele.x][ele.y + 1] == State::FRESH) {
                    grid[ele.x][ele.y + 1] = State::ROTTEN;
                    q.push({ele.x, ele.y + 1});
                    fresh--;
                }
                // left
                if (ele.y - 1 >= 0 && grid[ele.x][ele.y - 1] == State::FRESH) {
                    grid[ele.x][ele.y - 1] = State::ROTTEN;
                    q.push({ele.x, ele.y - 1});
                    fresh--;
                }
                // bottom
                if (ele.x + 1 < maxi && grid[ele.x + 1][ele.y] == State::FRESH) {
                    grid[ele.x + 1][ele.y] = State::ROTTEN;
                    q.push({ele.x + 1, ele.y});
                    fresh--;
                }
                // top
                if (ele.x - 1 >= 0 && grid[ele.x - 1][ele.y] == State::FRESH) {
                    grid[ele.x - 1][ele.y] = State::ROTTEN;
                    q.push({ele.x - 1, ele.y});
                    fresh--;
                }
            }
            ret += 1;
        }
        return fresh == 0 ? ret - 1 : -1;
    }
};