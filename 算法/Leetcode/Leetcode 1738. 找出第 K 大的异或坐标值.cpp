#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int> que;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                matrix[i][j] ^= matrix[i][j - 1];
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] ^= matrix[i - 1][j];
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                que.push(matrix[i][j]);
            }
        }
        while (--k) {
            que.pop();
        }
        return que.top();
    }
};