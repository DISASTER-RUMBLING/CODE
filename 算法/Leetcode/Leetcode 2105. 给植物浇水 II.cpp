#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int res = 0;
        int l = 0, r = plants.size() - 1;
        int Alice = capacityA;
        int Bob = capacityB;
        while (l < r) {
            if (Alice < plants[l]) {
                res++;
                Alice = capacityA;
            }
            Alice -= plants[l++];
            if (Bob < plants[r]) {
                res++;
                Bob = capacityB;
            }
            Bob -= plants[r--];
        }
        if (l == r && max(Alice, Bob) < plants[l]) {
            res++;
        }
        return res;
    }

};