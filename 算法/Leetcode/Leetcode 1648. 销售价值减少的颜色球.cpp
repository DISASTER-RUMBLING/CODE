#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end());
        //now是表示现在指向的数字，num表示现在的数字，nums表示现在有几个数字
        long long res = 0, now = inventory.size() - 2, num = inventory[now + 1], nums = 1, mod = 1e9 + 7;
        while (orders) {
            while (now >= 0 && inventory[now] == num) {
                now--;
                nums++;
            }
            long long times;
            if (now < 0) {
                times = orders / nums;
                orders %= nums;
                if (times) {
                    res += ((num + num - times + 1) * times / 2) * nums;
                    num -= times;
                    res %= mod;
                }
                res += (orders * num);
                res %= mod;
                orders = 0;
            }
            else {
                if ((num - inventory[now]) * nums >= orders) {
                    times = orders / nums;
                    orders -= times * nums;
                    res += ((num * 2 - times + 1) * times / 2) * nums;
                    num -= times;
                    res += (num * orders);
                    orders = 0;
                }
                else {
                    times = num - inventory[now];
                    res += ((num * 2 - times + 1) * (times) / 2) * nums;
                    orders -= (num - inventory[now]) * nums;
                }
                num = inventory[now];
                now--;
                nums++;
                res %= mod;
            }
        }
        return res;
    }

};