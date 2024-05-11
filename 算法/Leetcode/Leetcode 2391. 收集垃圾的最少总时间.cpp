#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sz = garbage.size();
        vector<vector<int>> arr(3, vector<int>(1 + sz));
        int res = 0;
        for (int i = 1; i <= sz; i++) {
            for (int j = 0; j < garbage[i - 1].size(); j++) {
                if (garbage[i - 1][j] == 'M') {
                    arr[0][i]++;
                }
                else if (garbage[i - 1][j] == 'P') {
                    arr[1][i]++;
                }
                else {
                    arr[2][i]++;
                }
            }
            arr[0][i] += arr[0][i - 1];
            arr[1][i] += arr[1][i - 1];
            arr[2][i] += arr[2][i - 1];
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= sz; j++) {
                if (j > 1) {
                    res += travel[j - 2];
                }
                res += (arr[i][j] - arr[i][j - 1]);
                if (arr[i][j] == arr[i][sz]) {
                    break;
                }
            }
        }
        return res;;
    }

};