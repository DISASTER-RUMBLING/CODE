#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class SeatManager {
public:

    string now = "";

    SeatManager(int n) {
        now.resize(n, '0');
    }

    int reserve() {
        int tar = now.find('0');
        now[tar] = '1';
        return tar + 1;
    }

    void unreserve(int seatNumber) {
        now[seatNumber - 1] = '0';
        return;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */