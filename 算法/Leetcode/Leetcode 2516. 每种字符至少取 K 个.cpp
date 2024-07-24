#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> arr(3, 0);
        int sz = s.size(), res = sz, a = 0, b = 0, c = 0, l = 0;
        for (int i = 0; i < sz; i++) {
            arr[(int)(s[i] - 'a')] += 1;
        }
        if (arr[0] < k || arr[1] < k || arr[2] < k) {
            return -1;
        }
        for (int r = 0; r < sz; r++) {
            if (s[r] == 'a') {
                a++;
            }
            else if (s[r] == 'b') {
                b++;
            }
            else {
                c++;
            }
            while ((arr[0] - a) < k || (arr[1] - b) < k || (arr[2] - c) < k) {
                if (s[l] == 'a') {
                    a--;
                }
                else if (s[l] == 'b') {
                    b--;
                }
                else {
                    c--;
                }
                l++;
            }
            res = min(res, sz - (r - l + 1));
        }
        return res;
    }
};