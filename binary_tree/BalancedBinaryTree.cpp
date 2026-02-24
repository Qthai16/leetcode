#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/balanced-binary-tree/description/?envType=daily-question&envId=2026-02-08

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
    void dfs(TreeNode* node, int level, int& maxDepth) {
        if (!node) return;
        level++;
        dfs(node->left, level, maxDepth);
        dfs(node->right, level, maxDepth);
        maxDepth = max(maxDepth, level);
    }

    bool checkBalanced(TreeNode* root) {
        if (!root) return true;
        int maxleft = 0, maxright = 0;
        dfs(root->left, 0, maxleft);
        dfs(root->right, 0, maxright);
        return abs(maxleft - maxright) <= 1;
    }

    void inorder(TreeNode* node, vector<TreeNode*>& ret) {
        if (!node) return;
        if (node->left) inorder(node->left, ret);
        ret.push_back(node);
        if (node->right) inorder(node->right, ret);
    }

    bool isBalanced(TreeNode *root) {
        vector<TreeNode*> ret;
        inorder(root, ret);
        for (const auto& node : ret) {
            if (!checkBalanced(node)) return false;
        }
        return true;
    }
};