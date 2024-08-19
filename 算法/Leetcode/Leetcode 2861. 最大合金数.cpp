#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:


    bool Check(int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost, int mid) {
        int szc = composition.size(), szs = stock.size(), num = 0;
        for (int i = 0; i < szc; i++) {
            long long use = 0;
            bool flag = 1;
            for (int j = 0; j < szs; j++) {
                if (stock[j] < ((long long)mid * (long long)composition[i][j])) {
                    use += (((long long)((long long)mid * (long long)composition[i][j]) - (long long)stock[j]) * (long long)cost[j]);
                }
                if (use > budget) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int l = 0, r = 1e9;
        for (int i = 0; i < n; i++) {
            r = min(r, stock[i]);
        }
        r += budget + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(budget, composition, stock, cost, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }


};