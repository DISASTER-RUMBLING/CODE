#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int sz = trust.size();
        vector<int> arr1(n, -1), arr2(n, 0);
        for (int i = 0; i < sz; i++) {
            arr1[trust[i][0] - 1] = trust[i][1] - 1;
            arr2[trust[i][1] - 1] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (arr1[i] == -1 && arr2[i] == n - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};