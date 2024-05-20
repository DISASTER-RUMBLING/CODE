#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<iostream>

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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) {
            return -1; // 左子树不平衡
        }

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) {
            return -1; // 右子树不平衡
        }

        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // 当前节点不平衡
        }

        return max(leftHeight, rightHeight) + 1; // 返回当前节点的高度
    }
};
