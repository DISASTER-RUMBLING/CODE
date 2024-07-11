#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        map<char, bool> mmp;
        for (int i = 0; i < astr.size(); i++) {
            if (!mmp[astr[i]]) {
                mmp[astr[i]] += 1;
            }
            else {
                return false;
            }
        }
        return true;
    }
};