#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> sta;
        vector<int> res(prices.size(), 0);
        for (int i = 0; i < prices.size(); i++) {
            while (!sta.empty() && prices[i] <= prices[sta.top()]) {
                res[sta.top()] = prices[sta.top()] - prices[i];
                sta.pop();
            }
            sta.push(i);
        }
        while (!sta.empty()) {
            res[sta.top()] = prices[sta.top()];
            sta.pop();
        }
        return res;
    }
};