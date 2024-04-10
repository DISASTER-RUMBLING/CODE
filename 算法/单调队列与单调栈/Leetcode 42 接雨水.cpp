#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> p;
        int res = 0;
        for (int i = 0, n = height.size(); i < n; i++) {
            while (!p.empty() && height[p.top()] < height[i]) {
                int low = height[p.top()];
                p.pop();
                if (p.empty()) {
                    break;
                }
                res += ((height[p.top()] > height[i] ? height[i] : height[p.top()]) - low) * (i - p.top() - 1);
            }
            p.push(i);
        }
        return res;
    }
};