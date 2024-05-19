#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    int getWinner(vector<int>& arr, int k) {
        int sz = arr.size();
        if (k >= sz) {
            sort(arr.begin(), arr.end());
            return arr[sz - 1];
        }
        int flag = 0;
        for (int i = 0; i < sz; i++) {
            if (k == 1 && flag == 1) {
                return arr[i];
            }
            for (int j = 1; j <= (k - flag); j++) {
                if (arr[i] < arr[i + j]) {
                    arr.push_back(arr[i]);
                    flag = 1;
                    break;
                }
                if (j == (k - flag)) {
                    return arr[i];
                }
            }
        }
        return 0;
    }

};