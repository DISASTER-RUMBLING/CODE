#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> mmp;
        int sz = paths.size();
        for (int i = 0; i < sz; i++) {
            mmp[paths[i][0]] = paths[i][1];
            mmp[paths[i][1]];
        }
        for (int i = 0; i < sz; i++) {
            if (mmp.find(paths[i][1])->second == "") {
                return paths[i][1];
            }
        }
        return "";
    }
};