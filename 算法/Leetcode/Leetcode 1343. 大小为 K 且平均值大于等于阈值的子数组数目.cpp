#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int now = 0, res = 0;
        for (int i = 0; i < k; i++) {
            now += arr[i];
        }
        for (int i = k; i < arr.size(); i++) {
            if (now >= (threshold * k)) {
                res++;
            }
            now += (arr[i] - arr[i - k]);
        }
        if (now >= (threshold * k)) {
            res++;
        }
        return res;
    }
};