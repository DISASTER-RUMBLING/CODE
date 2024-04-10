#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> h;
        int max = 0, now = -1, len = s.size();
        for (int i = 0; i < len; i++) {
            if (h.find(s[i]) != h.end()) {
                now = now > h.find(s[i])->second ? now : h.find(s[i])->second;
            }
            h[s[i]] = i;
            max = max > (i - now) ? max : i - now;
        }
        return max;
    }
};