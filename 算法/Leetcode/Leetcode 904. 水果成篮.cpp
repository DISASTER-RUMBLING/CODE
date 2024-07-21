#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, ans = 0, res = 0, sz = fruits.size(), tree1 = -1, tree2 = -1, t1 = 0, t2 = 0;
        while (r < sz) {
            if (tree1 == -1 || tree1 == fruits[r]) {
                tree1 = fruits[r];
                t1++;
            }
            else if (tree2 == -1 || tree2 == fruits[r]) {
                tree2 = fruits[r];
                t2++;
            }
            else {
                while (t1 != 0 && t2 != 0) {
                    if (tree1 == fruits[l]) {
                        t1--;
                    }
                    else {
                        t2--;
                    }
                    l++;
                }
                if (t2 == 0) {
                    tree2 = fruits[r];
                    t2++;
                }
                else {
                    tree1 = fruits[r];
                    t1++;
                }
            }
            r++;
            res = max(t1 + t2, res);
        }
        return res;
    }
};