#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule-ii/description/

#include "../debug/StrUtils.h"

class Solution {
public:
    enum State {
        UNVISITED = 0,
        VISITING = 1,
        VISITED = 2
    };

    void bfs() {
        
    }

    bool dfs(const std::vector<std::vector<int>>& adjs, std::vector<int> &ret, std::stack<int> &s, vector<State> &visited, int course) {
        // topological order sort
        visited[course] = State::VISITING;
        for (const auto &child: adjs[course]) {
            if (visited[child] == State::VISITING)
                return false;
            if (visited[child] == State::UNVISITED && !dfs(adjs, ret, s, visited, child))
                return false;
        }
        s.push(course);
        visited[course] = State::VISITED;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adjs;
        adjs.resize(numCourses);
        for (const auto &v: prerequisites) {
            adjs[v[0]].push_back(v[1]);
        }
        // for (auto i = 0; i < adjs.size(); i++) {
        //     std::cout << libs::simple_format("{}: {}", i, adjs[i]) << std::endl;
        // }
        stack<int> s;
        vector<int> ret;
        vector<State> visited(numCourses, State::UNVISITED);
        for (auto i = 0; i < adjs.size(); i++) {
            if (visited[i] == State::UNVISITED && !dfs(adjs, ret, s, visited, i))
                return {}; // graph contains a cycle
        }
        while (!s.empty()) {
            auto v = s.top();
            ret.push_back(v);
            s.pop();
        }
        return {ret.rbegin(), ret.rend()};
    }
};
