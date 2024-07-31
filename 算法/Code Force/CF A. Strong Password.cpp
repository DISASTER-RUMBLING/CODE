#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int calculateTime(const string& s) {
    int time = 2;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            time += 1;
        }
        else {
            time += 2;
        }
    }
    return time;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int maxTime = calculateTime(s);
        string bestString = s;
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i <= s.size(); i++) {
                string newStr = s.substr(0, i) + c + s.substr(i);
                int newTime = calculateTime(newStr);
                if (newTime > maxTime) {
                    maxTime = newTime;
                    bestString = newStr;
                }
            }
        }

        cout << bestString << endl;
    }

    return 0;
}
