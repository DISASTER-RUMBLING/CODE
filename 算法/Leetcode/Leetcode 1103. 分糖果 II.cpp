#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int now = 0, num = 1;;
        while (candies > 0) {
            res[now] += candies >= num ? num : candies;
            candies -= (num++);
            now++;
            if (now == num_people) {
                now = 0;
            }
        }
        return res;
    }
};