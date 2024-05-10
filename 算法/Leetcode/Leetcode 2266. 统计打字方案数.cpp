#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:

    int countTexts(string pressedKeys) {
        vector<long long> res(pressedKeys.size() + 1);
        res[0] = 1;
        res[1] = 1;
        long long mod = 1e9 + 7;
        for (int i = 1; i < pressedKeys.size(); i++) {
            res[i + 1] += res[i];
            if (pressedKeys[i] == pressedKeys[i - 1]) {
                res[i + 1] += res[i - 1];
                if (i >= 2 && pressedKeys[i - 1] == pressedKeys[i - 2]) {
                    res[i + 1] += res[i - 2];
                    if (i >= 3 && (pressedKeys[i] == '7' || pressedKeys[i] == '9') && pressedKeys[i] == pressedKeys[i - 3]) {
                        res[i + 1] += res[i - 3];
                    }
                }
            }
            res[i + 1] %= mod;
        }
        return (int)res[pressedKeys.size()];
    }

};