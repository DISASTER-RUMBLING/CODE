#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<string>

using namespace std;

class TimeMap {
public:
    map<string, vector<pair<int, string>>> mmp;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        mmp[key].push_back({ timestamp,value });
        return;
    }

    string get(string key, int timestamp) {
        if (mmp[key].empty()) {
            return "";
        }
        int l = -1, r = mmp[key].size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mmp[key][mid].first <= timestamp) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (l >= 0) {
            return mmp[key][l].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */