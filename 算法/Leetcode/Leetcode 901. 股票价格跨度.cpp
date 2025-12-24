#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class StockSpanner {
public:

    stack<int> sta;
    vector<int> arr;

    StockSpanner() {

    }

    int next(int price) {
        arr.push_back(price);
        while (!sta.empty() && arr[sta.top() - 1] <= price) {
            sta.pop();
        }

        int top = sta.size() ? sta.top() - 1 : 0;
        sta.push(arr.size());
        return arr.size() == 1 ? 1 : (sta.size() == 1 ? arr.size() : arr.size() - top - 1);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */