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

    bool Check(TreeNode* left, TreeNode* right) {
        if ((left == nullptr && right == nullptr)) {
            return true;
        }
        if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr)) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return Check(left->left, right->left) && Check(left->right, right->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == nullptr && q == nullptr)) {
            return true;
        }
        return Check(p, q);
    }
};