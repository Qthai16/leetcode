#include <bits/stdc++.h>
using namespace std;

struct City {
    int pop; // population
    vector<City*> neighbor;
    vector<int> neiPop;
};

class Solution {
public:
    void dfs(City* node, stack<City*>& path, unordered_set<City*> visited, vector<int>& traffics) {
        if (node == nullptr) return;
        if (visited.find(node) != visited.end()) return;
        path.push(node);
        for (const auto& n : node->neighbor) {
            dfs(node, path, visited, traffics);
        }
    }

    unordered_map<int, int> maximumTraffic(vector<City*> nodes) {
        
    }
};