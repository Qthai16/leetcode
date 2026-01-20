#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/invert-binary-tree

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
    TreeNode *dfs(TreeNode *n) {
        if (n == nullptr) return n;
        auto left = dfs(n->left);
        auto right = dfs(n->right);
        swap(left, right);
        n->left = left;
        n->right = right;
        return n;
    }
    TreeNode *invertTree(TreeNode *root) {
        return dfs(root);
    }
};