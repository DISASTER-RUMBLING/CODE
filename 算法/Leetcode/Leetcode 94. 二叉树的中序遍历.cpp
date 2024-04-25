#define _CRT_SECURE_NO_WARNINGS
#include<vector>

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

    void In_Order(TreeNode* root, vector<int>* arr) {
        if (root == nullptr) {
            return;
        }
        In_Order(root->left, arr);
        arr->push_back(root->val);
        In_Order(root->right, arr);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        In_Order(root, &arr);
        return arr;
    }
};