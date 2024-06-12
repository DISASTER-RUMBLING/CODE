#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100 - (purchaseAmount % 10 > 4 ? (1 + purchaseAmount / 10) * 10 : (purchaseAmount / 10) * 10);
    }
};