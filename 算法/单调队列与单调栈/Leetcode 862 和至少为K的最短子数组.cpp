#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long n = nums.size(), ans = n + 1;
        vector<long long> p(1 + n, 0);
        for (long long i = 1; i <= n; i++) {
            p[i] += p[i - 1] + nums[i - 1];
        }
        deque<long long> q;
        q.push_back(0);
        for (long long i = 1; i <= n; i++) {
            while (!q.empty() && (p[i] - p[q.front()]) >= k) {
                ans = ans < (i - q.front()) ? ans : (i - q.front());
                q.pop_front();
            }
            while (!q.empty() && p[q.back()] > p[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        if (ans == (n + 1)) {
            return -1;
        }
        return ans;
    }
};