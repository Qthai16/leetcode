#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        int maxd = INT_MIN;
        int depth = 0;
        auto dfs = [&](auto &fn, TreeNode *node, int depth) {
            if (node == nullptr) return;
            if (node->left) {
                fn(fn, node->left, depth + 1);
            }
            if (node->right) {
                fn(fn, node->right, depth + 1);
            }
            maxd = max(maxd, depth);
        };
        dfs(dfs, root, 0);
        return maxd != INT_MIN ? maxd + 1 : 0;
    }
};