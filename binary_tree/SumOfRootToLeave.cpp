#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/?envType=daily-question&envId=2026-02-24

//  Definition for a binary tree node.
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
    int sumRootToLeaf(TreeNode *root) {
        auto dfs = [](auto& fn, TreeNode *node, int& cur, int& sum) {
            if (!node) return;
            cur = node->val + (cur << 1);
            if (!node->left && !node->right) {
                sum += cur;
                cur = (cur >> 1); // backtrack
                return;
            }
            if (node->left) {
                fn(fn, node->left, cur, sum);
            }
            if (node->right) {
                fn(fn, node->right, cur, sum);
            }
            cur = (cur >> 1); // backtrack
        };
        int sum = 0, cur = 0;
        dfs(dfs, root, cur, sum);
        return sum;
    }
};