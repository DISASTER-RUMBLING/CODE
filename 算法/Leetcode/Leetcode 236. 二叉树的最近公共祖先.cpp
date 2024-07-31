#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool Find(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res) {
        if (root == nullptr) {
            return false;
        }
        bool flag1 = Find(root->left, p, q, res);
        bool flag2 = Find(root->right, p, q, res);
        if ((root == p || root == q) && (flag1 || flag2)) {
            res = root;
        }
        else if (flag1 && flag2 && res == nullptr) {
            res = root;
        }
        else if (root == p || root == q) {
            return true;
        }
        return flag1 || flag2;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        Find(root, p, q, res);
        return res;
    }
};