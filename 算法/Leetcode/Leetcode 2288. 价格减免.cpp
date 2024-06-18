#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        double dis = 1.0 - discount * 0.01;
        string res = "", word;
        int now = 0;
        stringstream ss(sentence);
        while (ss >> word) {
            if (res.size() > 0) {
                res.push_back(' ');
            }
            if (word.size() > 1 && word[0] == '$' && all_of(word.begin() + 1, word.end(), ::isdigit)) {
                stringstream s;
                s << fixed << setprecision(2) << '$' << stoll(word.substr(1)) * dis;
                res += s.str();
            }
            else {
                res += word;
            }
        }
        return res;
    }
};

int main() {




}