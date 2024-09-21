#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int sz = edges.size(), res = 0;
        vector<long long> arr(sz, 0);
        for (int i = 0; i < sz; i++) {
            arr[edges[i]] += i;
            res = arr[res] > arr[edges[i]] ? res : (arr[res] == arr[edges[i]] ? min(res, edges[i]) : edges[i]);
        }
        return res;
    }
};