#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long ans = 0, now = 1, res = 0;
        for (int i = s.size() - 1; i > (s.size() - k - 1); i--) {
            ans = ((ans * power) + (s[i] & 31)) % modulo;
            now = now * power % modulo;
        }
        res = (ans == hashValue ? s.size() - k : res);
        for (int i = s.size() - k - 1; i >= 0; i--) {
            ans = (ans * power + (s[i] & 31) - now * (s[i + k] & 31) % modulo + modulo) % modulo;
            res = (ans == hashValue ? i : res);
        }
        return s.substr(res, k);
    }
};