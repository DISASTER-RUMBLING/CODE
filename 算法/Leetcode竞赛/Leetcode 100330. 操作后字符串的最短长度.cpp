#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int now = 0, times = 0;
        vector<int> arr(26);
        for (int i = 0; i < s.size(); i++) {
            arr[(int)(s[i] - 'a')] += 1;
        }
        for (int i = 0; i < 26; i++) {
            while (arr[i] >= 3) {
                arr[i] -= 2;
                times += 2;
            }
        }
        return s.size() - times;
    }
};