#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        map<string, int> mmp;
        priority_queue<pair<int, string>> que;
        for (int i = 0; i < words.size(); i++) {
            mmp[words[i]]++;
        }
        for (auto x : mmp) {
            que.push({ -x.second,x.first });
            if (que.size() > k) {
                que.pop();
            }
        }
        while (!que.empty()) {
            res.insert(res.begin(), que.top().second);
            que.pop();
        }
        return res;
    }
};