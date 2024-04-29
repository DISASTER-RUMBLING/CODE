#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

string simplifyPath(string path) {
    int pos, flag = 0;
    deque<string> sta1, sta2;
    string now;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] != '/' && flag) {
            now.push_back(path[i]);
        }
        else if (!flag && path[i] == '/') {
            flag = 1;
        }
        else if (flag && path[i] == '/' && now != "") {
            if (now == "..") {
                if (!sta1.empty()) {
                    sta1.pop_back();
                }
            }
            else if (now != ".") {
                sta1.push_back(now);
            }
            now = "";
        }
    }
    if (now != "") {
        if (now == "..") {
            if (!sta1.empty()) {
                sta1.pop_back();
            }
        }
        else if (now != ".") {
            sta1.push_back(now);
        }
        now = "";
    }
    while (!sta1.empty()) {
        now += '/';
        now += sta1.front();
        sta1.pop_front();
    }
    if (now == "") {
        return "/";
    }
    return now;
}