#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

string predictPartyVictory(string senate) {
    while (1) {
        int flag = 0;
        string now;
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'R') {
                if (flag <= 0) {
                    now.push_back(senate[i]);
                }
                flag--;
            }
            else {
                if (flag >= 0) {
                    now.push_back(senate[i]);
                }
                flag++;
            }
        }
        if (flag != 0) {
            if (flag > 0) {
                for (int i = 0; flag > 0 && i < now.size(); i++) {
                    if (now[i] == 'R') {
                        now.erase(i,1);
                        flag--;
                    }
                }
            }
            else {
                for (int i = 0; flag < 0 && i < now.size(); i++) {
                    if (now[i] == 'D') {
                        now.erase(i,1);
                        flag++;
                    }
                }
            }
        }
        senate = now;
        flag = 0;
        for (int i = 0; i < senate.size() - 1; i++) {
            if (senate[i] != senate[i + 1]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            if (senate[0] == 'D') {
                return "Dire";
            }
            else {
                return "Radiant";
            }
        }
    }
}