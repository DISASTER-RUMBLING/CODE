#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:


    bool Check(vector<int>& heights, int bricks, int ladders, int mid) {
        priority_queue<int> que;
        for (int i = 0; i < mid; i++) {
            if (heights[i + 1] > heights[i]) {
                que.push(heights[i + 1] - heights[i]);
            }
        }
        while (!que.empty()) {
            if (ladders) {
                que.pop();
                ladders--;
            }
            else {
                bricks -= que.top();
                que.pop();
            }
            if (bricks < 0) {
                return false;
            }
        }
        return true;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int l = 0, r = heights.size();
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(heights, bricks, ladders, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }

};