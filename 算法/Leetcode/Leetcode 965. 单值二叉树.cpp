#define _CRT_SECURE_NO_WARNINGS

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

    bool Check(TreeNode* root, int k) {
        if (root == nullptr) {
            return true;
        }
        if (root->val != k) {
            return false;
        }
        return Check(root->left, k) && Check(root->right, k);
    }

    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return Check(root, root->val);
    }
};