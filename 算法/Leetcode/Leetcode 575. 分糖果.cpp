#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int res = 1;
        sort(candyType.begin(), candyType.end());
        for (int i = 1; i < candyType.size(); i++) {
            if (candyType[i - 1] != candyType[i]) {
                res++;
            }
        }
        return (candyType.size() / 2) >= res ? res : res - (res - (candyType.size() / 2));
    }
};