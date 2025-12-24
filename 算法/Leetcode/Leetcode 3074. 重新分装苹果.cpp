#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int num = 0, sum = 0, now = capacity.size() - 1;
        for (int i = 0; i < apple.size(); i++) {
            num += apple[i];
        }
        while (sum < num && now>=0) {
            sum += capacity[now--];
        }
        return capacity.size() - now - 1;
    }
};