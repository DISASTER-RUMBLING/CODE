#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0, sz1 = arr1.size(), sz2 = arr2.size();
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < sz1; i++) {
            if (i && arr1[i] == arr1[i - 1]) {
                continue;
            }
            int l = -1, r = sz2;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (arr2[mid] <= arr1[i]) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            if ((l<0 && abs(arr1[i] - arr2[r])>d)) {
                res++;
            }
            else if (r == sz2 && abs(arr1[i] - arr2[l]) > d) {
                res++;
            }
            else if (l >= 0 && r < sz2 && (abs(arr1[i] - arr2[r]) > d && abs(arr1[i] - arr2[l]) > d)) {
                res++;
            }
        }
        return res;
    }
};