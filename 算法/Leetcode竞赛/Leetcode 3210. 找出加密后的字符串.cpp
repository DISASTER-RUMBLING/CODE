#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            res.push_back(s[(i + k) % s.size()]);
        }
        return res;
    }
};