#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, res = 0;
        while (l <= r) {
            int ans = limit;
            ans -= people[r--];
            if (l <= r && people[l] <= ans) {
                ans -= people[l++];
            }
            res++;
        }
        return res;
    }
};