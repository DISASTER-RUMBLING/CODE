#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {
        arr = vector<vector<pair<int, int>>>(length, { {0,0} });
        times = 0;
    }

    void set(int index, int val) {
        if (arr[index].back().first == times) {
            arr[index].back().second = val;
        }
        else {
            arr[index].push_back({ times,val });
        }
        return;
    }

    int snap() {
        return times++;
    }

    int get(int index, int snap_id) {
        int l = -1, r = arr[index].size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (arr[index][mid].first <= snap_id) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return arr[index][l].second;
    }

private:
    //第一个int表示第几次快照，第二个int表示第n次快照中的数字
    vector<vector<pair<int, int>>> arr;
    int times;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */