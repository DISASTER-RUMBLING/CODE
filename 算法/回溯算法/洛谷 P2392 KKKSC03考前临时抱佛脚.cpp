#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;

////方法1
//#define MAX_N 20
//#define MAX_NUM 9999999
//int s[10] = { 0 };
////存储每个科目的每一题所需要的时间
//int t[10][MAX_NUM + 5];//t[i][j] TODO(1)
//int ans = 0;
//
////k表示做的题目数量,x表示是做的是第x科的习题集，l表示左大脑做题使用的时间，l表示右大脑做题使用的时间
//void dfs(int k, int x, int l, int r) {
//	//表示是否将题目全部做完
//	if (k == s[x]) {
//		//判断是否是最小的时间
//		int n = (l > r ? l : r);
//		ans = ans > n ? n : ans;
//		return;
//	}
//	//TODO(2)
//	//左大脑做第x科第k题
//	l += t[x][k];
//	//搜索该情况的状态子树
//	dfs(k + 1, x, l, r);
//	//换成右大脑做
//	l -= t[x][k];
//	//TODO(3)
//	r += t[x][k];
//	dfs(k + 1, x, l, r);
//	r -= t[x][k];
//	return;
//}
//
//int main() {
//	//输入每一科习题集的题目数量
//	for (int i = 0; i < 4; i++) {
//		scanf("%d", &s[i]);
//	}//TODO(4)
//	//输入每一科题集中每一题所需要的时间
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < s[i]; j++) {
//			scanf("%d", &t[i][j]);
//		}
//	}
//	//定义一个整形用于存储做完所有题集所要的时间
//	int total = 0;
//	//寻找做完每个习题集所要的最短时间
//	for (int i = 0; i < 4; i++) {
//		//定义一个最大时间，后面会缩短
//		ans = MAX_NUM;
//		//开始回溯
//		dfs(0, i, 0, 0);
//		total += ans;
//	}
//	printf("%d", total);
//
//	return 0;
//
//}



////方法2
//#define Max_N 20
//#define MAX_NUM 9999999
//int s[10], sum[10] = { 0 };
//int t[10][Max_N + 5];
//unordered_map<int, int> ind;
//
//int Solve(int k) {
//	//定义一个整形为最大值
//	int ans = MAX_NUM;
//	int T = (1 << s[k]) - 1;
//	for (int i = 0; i < T; i++) {
//		int j = i, l = 0, r = 0;
//		while (j) {
//			l += t[k][ind[j & -j]];
//			j -= (j & -j);
//		}
//		r = sum[k] - l;
//		int now = l > r ? l : r;
//		ans = ans > now ? now : ans;
//	}
//	return ans;
//}
//
//int main() {
//	//存储4科习题集中有多少题
//	for (int i = 0; i < 4; i++) {
//		scanf("%d", &s[i]);
//	}
//	//存储各习题集中每一题要花费多少时间，该科做完全部题且只用一边大脑所需要的时间
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < s[i]; j++) {
//			scanf("%d", &t[i][j]);
//			sum[i] += t[i][j];
//		}
//	}
//	//用于判断当前题目是否做过
//	for (int i = 0, k = 0; i <= Max_N; i++, k *= 2) {
//		ind[k] = i;
//	}
//	//定义一个整形用于存储所需的最短做题时间
//	int ans = 0;
//	for (int i = 0; i < 4; i++) {
//		ans += Solve(i);
//	}
//	printf("%d", ans);
//
//	return 0;
//
//}
