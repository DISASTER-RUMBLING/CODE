#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int res = 0;
        stack<char> sta;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'E') {
                sta.push('E');
            }
            else {
                sta.pop();
            }
            res = max(res, (int)sta.size());
        }
        return res;
    }
};