#include<iostream>
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

  int find_max(TreeNode* root, int num) {
      TreeNode* now = root;
      while (now) {
          if (now->val == num) {
              break;
          }
          if (now->val > num) {
              if (now->left) {
                  now = now->left;
              }
              else {
                  break;
              }
          }
          else if (now->val < num) {
              if (now->right) {
                  now = now->right;
              }
              else {
                  break;
              }
          }
      }
      return now->val <= num ? now->val : -1;
  }

  int find_min(TreeNode* root, int num) {
      TreeNode* now = root;
      while (now) {
          if (now->val == num) {
              break;
          }
          if (now->val > num) {
              if (now->left) {
                  now = now->left;
              }
              else {
                  break;
              }
          }
          else if (now->val < num) {
              if (now->right) {
                  now = now->right;
              }
              else {
                  break;
              }
          }
      }
      return now->val >= num ? now->val : -1;
  }

  vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
      vector<vector<int>> res(queries.size(), vector<int>(2));
      for (int i = 0; i < queries.size(); i++) {
          res[i] = { find_max(root,queries[i]),find_min(root,queries[i]) };
      }
      return res;
  }