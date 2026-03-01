#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

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
     void arrr(TreeNode* root, vector<int>& arr) {
         if (!root) {
             return;
         }
         queue<TreeNode*> que;
         que.push(root);
         while (!que.empty()) {
             arr.push_back(que.front()->val);
             if (que.front()->left) {
                 que.push(que.front()->left);
             }
             if (que.front()->right) {
                 que.push(que.front()->right);
             }
             que.pop();
         }
         return;
     }

     int find0(vector<int>& arr, int num) {
         if (!arr.size()) {
             return -1;
         }
         int l = 0, r = arr.size(), mid;
         while (l + 1 < r) {
             mid = (l + r) >> 1;
             if (arr[mid] <= num) {
                 l = mid;
             }
             else {
                 r = mid;
             }
         }
         return arr[l] <= num ? arr[l] : -1;
     }

     int find1(vector<int>& arr, int num) {
         if (!arr.size()) {
             return -1;
         }
         int l = -1, r = arr.size() - 1, mid;
         while (l + 1 < r) {
             mid = (l + r) >> 1;
             if (arr[mid] < num) {
                 l = mid;
             }
             else {
                 r = mid;
             }
         }
         return arr[r] >= num ? arr[r] : -1;
     }

     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
         vector<vector<int>> res(queries.size(), vector<int>(2));
         vector<int> arr;
         arrr(root, arr);
         sort(arr.begin(), arr.end());
         for (int i = 0; i < queries.size(); i++) {
             res[i][0] = find0(arr, queries[i]);
             res[i][1] = find1(arr, queries[i]);
         }
         return res;
     }
 };