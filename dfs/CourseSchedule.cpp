#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool has_cycle(int u, const vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
        // dfs
        if (recStack[u])
            return true;
        if (visited[u])
            return false;
        visited[u] = true;
        recStack[u] = true;
        for (const auto &v: adj[u]) {
            if (has_cycle(v, adj, visited, recStack))
                return true;
        }
        recStack[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // detect cyclic in a directed graph
        // prerequisites[i][0] is vertices
        vector<vector<int>> adj;
        adj.resize(numCourses);
        for (const auto &v: prerequisites) {
            adj[v[0]].insert(adj[v[0]].end(), v.begin() + 1, v.end());
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && has_cycle(i, adj, visited, recStack))
                return false;
        }
        return true;
    }
};
