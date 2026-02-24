#include<iostream>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int& res) {
        int num = 0;
        if (root->left) {
            num += dfs(root->left, res);
        }
        if (root->right) {
            num += dfs(root->right, res);
        }
        if (!root->left && !root->right) {
            num = 1;
        }
        if (root->val == 1) {
            res += num;
        }
        return num * 2;
    }


    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};