#define _CRT_SECURE_NO_WARNINGS
#include<string>

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
    void pre(string& now, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        now += to_string(root->val);
        int flag = 0;
        if (root->left != nullptr) {
            now += '(';
            pre(now, root->left);
            now += ')';
            flag = 1;
        }
        if (root->right != nullptr) {
            if (!flag) {
                now += "()";
            }
            now += '(';
            pre(now, root->right);
            now += ')';
        }
        return;
    }

    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string now = "";
        pre(now, root);
        return now;
    }
};