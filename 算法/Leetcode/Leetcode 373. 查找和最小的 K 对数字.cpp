#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
	struct node {
		int x, y;
		int sum;

		node(int _x, int _y, int _sum) : x(_x), y(_y), sum(_sum) {}
	};

	struct Cmp {
		bool operator()(const node& x, const node& y) const {
			if (x.sum != y.sum) {
				return x.sum < y.sum;
			}
			return tie(x.x, x.y) < tie(y.x, y.y);
		}
	};

	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<vector<int>> res;
		set<node, Cmp> st;
		st.insert({ 0,0,nums1[0] + nums2[0] });
		int sz1 = nums1.size(), sz2 = nums2.size();
		map<pair<int, int>, bool> mmp;
		mmp[{0, 0}] = 1;
		while (res.size() < k) {
			node now = *st.begin();
			st.erase(now);
			res.push_back({ nums1[now.x],nums2[now.y] });
			if (now.x + 1 < sz1 && !mmp[{now.x + 1, now.y}]) {
				st.insert({ now.x + 1,now.y, nums1[now.x + 1] + nums2[now.y] });
				mmp[{ now.x + 1, now.y}] = 1;
			}
			if (now.y + 1 < sz2 && !mmp[{now.x, now.y + 1}]) {
				st.insert({ now.x,now.y + 1, nums1[now.x] + nums2[now.y + 1] });
				mmp[{ now.x, now.y + 1}] = 1;
			}
		}
		return res;
	}
};