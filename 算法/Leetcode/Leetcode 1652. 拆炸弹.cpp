#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (k > 0) {
            for (int j = 1; j <= k; j++) {
                res[i] += code[(i + j) % n];
            }
        }
        else if (k == 0) {
            res[i] = 0;
        }
        else {
            for (int j = 1; j <= -k; j++) {
                res[i] += code[(i - j + n) % n];
            }
        }
    }
    return res;
}