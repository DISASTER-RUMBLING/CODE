#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void Pre_Order(TreeNode* root, vector<TreeNode*>* arr) {
        if (root == nullptr) {
            return;
        }
        arr->push_back(root);
        Pre_Order(root->left, arr);
        Pre_Order(root->right, arr);
        return;
    }

    void flatten(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        vector<TreeNode*> arr;
        Pre_Order(root, &arr);
        for (int i = 0, sz = arr.size() - 1; i < sz; i++) {
            arr[i]->left = nullptr;
            arr[i]->right = arr[i + 1];
        }
        arr[arr.size() - 1]->left = arr[arr.size() - 1]->right = nullptr;
        return;
    }
};