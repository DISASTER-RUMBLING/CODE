#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    string removeTrailingZeros(string num) {
        while ((!num.empty()) && num.back() == '0') {
            num.erase(num.begin() + num.size() - 1);
        }
        return num;
    }
};