#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {

public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sta;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!sta.empty() && temperatures[i] > temperatures[sta.top()]) {
                res[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }
        return res;
    }
};