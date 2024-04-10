#define _CRT_SECURE_NO_WARNINGS
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto x : nums) {
            hash.insert(x);
        }
        int res = 0;
        for (auto x : hash) {
            if (!hash.count(x - 1)) {
                int y = x;
                while (hash.count(y + 1)) {
                    y++;
                }
                res = res > y - x + 1 ? res : y - x + 1;
            }
        }
        return res;
    }
};