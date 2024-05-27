#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

//假设构建的区间是[x,y)类型的
vector<int>& Build(vector<int> nums) {
	int sz = nums.size(), times = 2;
	while (sz > 0) {
		sz >> 1;
		times << 1;
	}
	vector<int> res(times + 1);
	_Build(res, nums, 1, times + 2, 1);
	return res;
}

//假设在已经开好的vector数组中创建线段树 
void _Build(vector<int>& tree, vector<int>& nums, int l, int r,int now) {
	if (l == r) {
		tree[now] = nums[now];
		return;
	}
	int mid = (l + r) >> 1;
	_Build(tree, nums, l, mid, now * 2);
	_Build(tree, nums, mid, r, now * 2 + 1);
	tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
	return;
}

//假设当前区间为[l,r],要查询区间[x,y]的值
int Find(vector<int>& tree, int l, int r, int now, int x, int y) {
	if (l <= x && r <= y) {
		return tree[now];
	}
	int ans = 0;
	int mid = (l + r) >> 1;
	if (mid > x) {
		ans += Find(tree, l, mid, now * 2, x, y);
	}
	if (mid < y) {
		ans += Find(tree, mid, r, now * 2 + 1, x, y);
	}
	return ans;
}

void Change(vector<int> tree, int l, int r, int pos, int val, int now) {
	if (l == r && now == pos) {
		tree[pos] = val;
	}
	int mid = (l + r) >> 1;
	if (pos < mid) {
		Change(tree, l, mid, pos, val, now * 2);
	}
	else {
		Change(tree, mid, r, pos, val, now * 2 + 1);
	}
	//条件
	tree[now] = max(tree[2 * now], tree[2 * now + 1]);
	return;
}

