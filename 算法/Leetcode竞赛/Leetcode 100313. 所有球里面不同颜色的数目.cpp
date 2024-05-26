#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> queryResults(int limit, vector<vector<int>>& queries) {
		vector<int> res(queries.size());
		map<int, int> use, bot;
		int times = 0;
		for (int i = 0; i < queries.size(); i++) {
			if (bot[queries[i][0]] != queries[i][1]) {
				if (bot[queries[i][0]] != 0) {
					if (use[bot[queries[i][0]]] > 0) {
						use[bot[queries[i][0]]]--;
						if (use[bot[queries[i][0]]] == 0) {
							times--;
						}
					}
					if (use[queries[i][1]] == 0) {
						times++;
					}
				}
				else {
					if (use[queries[i][1]] == 0) {
						times++;
					}
				}
				use[queries[i][1]] += 1;
			}
			bot[queries[i][0]] = queries[i][1];
			res[i] = times;
		}
		return res;
	}
};