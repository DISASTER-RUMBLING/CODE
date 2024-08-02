#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = -1, r = letters.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (letters[mid] <= target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return r == letters.size() ? letters[0] : letters[r];
    }
};