#define _CRT_SECURE_NO_WARNINGS
#include<queue>

using namespace std;


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

    bool Check(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return root == subRoot;
        }
        else if (root == nullptr) {
            return subRoot == root;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return Check(root->left, subRoot->left) && Check(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* now = que.front();
            que.pop();
            if (Check(now, subRoot)) {
                return true;
            }
            if (now->left != nullptr) {
                que.push(now->left);
            }
            if (now->right != nullptr) {
                que.push(now->right);
            }
        }
        return false;
    }
};