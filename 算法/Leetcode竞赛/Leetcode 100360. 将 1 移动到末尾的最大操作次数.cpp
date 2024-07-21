#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        vector<int> arr(1);
        int now = 0, res = 0;;
        while (now < s.size()) {
            if (s[now] == '1') {
                int ans = now, times = 0;
                while (ans < s.size() && s[ans] == '1') {
                    times++;
                    ans++;
                }
                arr[0] += times;
                now = ans;
            }
            else {
                while (now < s.size() && s[now] == '0') {
                    now++;
                }
                res += arr[0];
            }
        }
        return res;
    }

};