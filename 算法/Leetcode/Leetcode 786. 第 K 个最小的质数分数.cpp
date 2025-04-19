#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<tuple>

using namespace std;

class Solution {
public:


	struct node {
		int x, y;
		double num;

		node(int _x, int _y, double _num) :x(_x),
			y(_y),
			num(_num) {}

	};

	struct Cmp {
		bool operator()(const node& x, const node& y) const {
			if (x.num != y.num) {
				return x.num < y.num;
			}
			return tie(x.x, x.y) < tie(y.x, y.y);
		}
	};

	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
		vector<int> res(2, 0);
		set<node, Cmp> st;
		int sz = arr.size(), now = 0;
		st.insert(node(0, sz - 1, 1.0 * arr[0] / arr[sz - 1]));
		while (now < k) {
			node nd = *st.begin();
			st.erase(st.begin());
			if (nd.x + 1 < sz && nd.x + 1 < nd.y) {
				st.insert({ nd.x + 1,nd.y,(double)arr[nd.x + 1] / arr[nd.y] });
			}
			if (nd.y - 1 >= 0 && nd.x < nd.y - 1) {
				st.insert({ nd.x,nd.y - 1,(double)arr[nd.x] / arr[nd.y - 1] });
			}
			now++;
			if (now == k) {
				res[0] = arr[nd.x];
				res[1] = arr[nd.y];
			}
		}
		return res;
	}

};