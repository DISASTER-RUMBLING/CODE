#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

int maximumEnergy(vector<int>& energy, int k) {
    int sz = energy.size();
    vector<int> res(sz);
    for (int i = 0; i < k; i++) {
        res[i] = energy[i];
        for (int j = i + k; j < sz; j += k) {
            res[j] = max(res[j - k] + energy[j], energy[j]);
        }
    }
    int ans = -9999999;
    for (int i = sz - k; i < sz; i++) {
        ans = max(ans, res[i]);
    }
    return ans;
}