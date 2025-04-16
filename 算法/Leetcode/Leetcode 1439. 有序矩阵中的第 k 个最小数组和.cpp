#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
	struct node {
		vector<int> arr;
		int sum;

		node(vector<int> _arr, int _sum) : arr(_arr),
			sum(_sum) {}

	};

	struct Cmp {
		bool operator()(const node& a, const node& b) const {
			if (a.sum != b.sum) {
				return a.sum < b.sum;
			}
			return a.arr < b.arr;
		}
	};


	int kthSmallest(vector<vector<int>>& mat, int k) {
		set<node, Cmp> st;
		int sz = mat.size(), now = 0, res = 0;
		for (int i = 0; i < sz; i++) {
			res += mat[i][0];
		}
		vector<int> arr(sz, 0);
		st.insert({ arr,res });
		while (now < k) {
			node use = *(st.begin());
			st.erase(st.begin());
			for (int i = 0; i < sz; i++) {
				use.arr[i]++;
				if (use.arr[i] < mat[i].size()) {
					st.insert({ use.arr,use.sum - mat[i][use.arr[i] - 1] + mat[i][use.arr[i]] });
				}
				use.arr[i]--;
			}
			res = use.sum;
			now++;
		}
		return res;
	}
};