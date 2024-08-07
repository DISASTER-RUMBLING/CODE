#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<iostream>

using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int, int> mmp;
        int sz = times.size(), now = persons[0], nums = 1, flag = 0;
        mmp[now] += 1;
        for (int i = 1; i < sz; i++) {
            mmp[persons[i]] += 1;
            if (now != persons[i] && mmp[now] <= mmp[persons[i]]) {
                arr.push_back({ now,times[i] == 0 ? 0 : times[i] - 1 });
                now = persons[i];
                nums = mmp[persons[i]];
            }
        }
        arr.push_back({ now,times[sz - 1] });
    }

    int q(int t) {
        if (t >= arr.back().second) {
            return arr.back().first;
        }
        int l = -1, r = arr.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (arr[mid].second < t) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return arr[r].first;
    }

private:
    //第一个int存票数领先的人，第二个int存的是领先的时间
    vector<pair<int, int>> arr;

};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */