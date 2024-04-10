#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> h;
        for (auto x : nums) {
            if (h.find(x) != h.end()) {
                return true;
            }
            h[x] = x;
        }
        return false;
    }
};