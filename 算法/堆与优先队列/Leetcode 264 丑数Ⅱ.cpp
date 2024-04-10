#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        long long tmp;
        while (n--) {
            tmp = *s.begin();
            s.erase(s.begin());
            if (tmp % 5 == 0) {
                s.insert(tmp * 5);
            }
            else if (tmp % 3 == 0) {
                s.insert(tmp * 3);
                s.insert(tmp * 5);
            }
            else {
                s.insert(tmp * 5);
                s.insert(tmp * 3);
                s.insert(tmp * 2);
            }
        }
        return tmp;
    }
};