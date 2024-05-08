#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:

    int wateringPlants(vector<int>& plants, int capacity) {
        int res = 0;
        queue<int> que;
        for (int i = 0; i < plants.size(); i++) {
            que.push(plants[i]);
        }
        int num = 0;
        while (!que.empty()) {
            res += (num);
            int now = capacity;
            while (!que.empty() && now >= que.front()) {
                res++;
                num++;
                now -= (que.front());
                que.pop();
            }
            if (!que.empty()) {
                res += (num);
            }
        }
        return res;
    }

};