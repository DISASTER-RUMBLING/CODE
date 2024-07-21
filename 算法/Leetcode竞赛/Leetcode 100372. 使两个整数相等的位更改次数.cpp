#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        return (n & k) != k ? -1 : __builtin_popcount(n ^ k);
    }
};