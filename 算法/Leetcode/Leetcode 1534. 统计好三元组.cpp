#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class Solution {
public:
	int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
		int res = 0, sz = arr.size();
		for (int i = 0; i < sz - 2; i++) {
			for (int j = i + 1; j < sz - 1; j++) {
				if (abs(arr[i] - arr[j]) <= a) {
					for (int k = j + 1; k < sz; k++) {
						if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
							res++;
						}
					}
				}
			}
		}
		return res;
	}
};