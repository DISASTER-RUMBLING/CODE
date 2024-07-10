#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        long long res = (long long)currentEnergy;
        if (currentEnergy >= enemyEnergies[0]) {
            for (int i = 1; i < enemyEnergies.size(); i++) {
                res += enemyEnergies[i];
            }
        }
        return (long long)(res / enemyEnergies[0]);
    }
};